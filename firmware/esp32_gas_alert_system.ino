#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
#include <math.h>

// 12 // WiFi Credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "your_ssid";
char pass[] = "your_password";

// 17 // Sensor & Actuator Pins
#define GAS_SENSOR_ANALOG 34
#define BUZZER_PIN 23
#define SERVO_PIN 2
#define D5_PIN 5

// 23 // Motor A Pins
#define MOTOR1_PIN1 27
#define MOTOR1_PIN2 26
#define ENABLE1_PIN 14

bool gasDetected = false, manualD5Control = false, servoActive = false,
     buzzerManualControl = false;
unsigned long buzzerOffTime = 0, motorOffTime = 0;

Servo myServo;
BlynkTimer timer;

// ** MQ-2 Sensor Constants **
#define RL 10.0
#define A 1000.0
// Correction: Replaced invalid #define B-2.2 with a constant float
const float B = -2.2;

float R0 = 9.8;

// ** Function to convert Raw value to PPM **
float getPPM(int rawValue) {
  float voltage = (rawValue / 4095.0) * 3.3;
  float Rs = ((3.3 * RL) / voltage) - RL;
  // B is used as the constant here
  return A * pow(Rs / R0, B);
}

// ** Function to read and send sensor data **
void sendSensorData() {
  int gasLevel = analogRead(GAS_SENSOR_ANALOG);
  
  // Line 51 (originally 42) was misplaced and has been moved here
  float ppm = getPPM(gasLevel);
  Blynk.virtualWrite(V1, ppm);

  // ** Control D5 automatically unless manual mode is ON **
  if (!manualD5Control) {
    // Turns D5 (e.g., LED) HIGH (ON) if gas is safe, LOW (OFF) if rising.
    digitalWrite(D5_PIN, (ppm < 800) ? HIGH : LOW);
  }

  // ** Disable manual mode if high gas detected and trigger actions **
  if (ppm > 900 && !gasDetected) {
    manualD5Control = false; // Override manual control
    Blynk.logEvent("gas_alert", "High Gas Level Detected!");
    gasDetected = true;

    if (!buzzerManualControl) digitalWrite(BUZZER_PIN, HIGH); // Auto buzzer
    
    // Start exhaust fan (Motor A)
    digitalWrite(MOTOR1_PIN1, LOW);
    digitalWrite(MOTOR1_PIN2, HIGH);
    digitalWrite(ENABLE1_PIN, HIGH);

    myServo.write(180); // Open valve/window
    buzzerOffTime = millis() + 10000; // 10 seconds buzzer
    motorOffTime = millis() + 30000; // 30 seconds motor
  }

  // ** Gas level drops, start system shutdown sequence **
  if (ppm < 700 && gasDetected) {
    if (buzzerOffTime && millis() >= buzzerOffTime) {
      if (!buzzerManualControl) digitalWrite(BUZZER_PIN, LOW);
      buzzerOffTime = 0;
    }

    if (motorOffTime && millis() >= motorOffTime) {
      // Stop exhaust fan (Motor A)
      digitalWrite(MOTOR1_PIN1, LOW);
      digitalWrite(MOTOR1_PIN2, LOW);
      digitalWrite(ENABLE1_PIN, LOW);
      
      gasDetected = false;
      motorOffTime = 0;
      myServo.write(0); // Close valve/window
    }
  }
}

// ** Blynk Manual Controls **

// V0: Motor Control (Slider or Button)
BLYNK_WRITE(V0) {
  // If param is 1 (ON), Enable is HIGH, Motor direction is HIGH
  digitalWrite(ENABLE1_PIN, param.asInt() ? HIGH : LOW);
  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, param.asInt() ? HIGH : LOW);
}

// V2: Servo Control (Button)
BLYNK_WRITE(V2) {
  myServo.write(param.asInt() ? 180 : 0);
}

// V3: Buzzer Manual Control (Button)
BLYNK_WRITE(V3) {
  digitalWrite(BUZZER_PIN, param.asInt());
  buzzerManualControl = param.asInt(); // Set manual control flag
}


// ** Blynk Control for D5 (V4) **
BLYNK_WRITE(V4) {
  digitalWrite(D5_PIN, param.asInt());
  manualD5Control = true; // Flag that D5 is manually controlled
}

void setup() {
  // Lines 116-133 have been correctly placed here
  Serial.begin(115200);
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(ENABLE1_PIN, OUTPUT);
  pinMode(GAS_SENSOR_ANALOG, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(D5_PIN, OUTPUT);
  
  // Initial state setup
  digitalWrite(D5_PIN, HIGH); // D5 LED ON by default (indicating safe)
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(ENABLE1_PIN, LOW); // Motor OFF
  
  // Servo initialization
  myServo.attach(SERVO_PIN, 500, 2400);
  myServo.write(0); // Close valve/window initially
  
  // Blynk and Timer setup
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, sendSensorData); // Read sensor and send data every second
}

void loop() {
  Blynk.run();
  timer.run(); // This is necessary for the timer to work!
}
