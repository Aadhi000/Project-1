# 💻 Software Tools

### 1. **Arduino IDE**
Used to program and upload code to the ESP32 microcontroller. The IDE supports required libraries for sensor interfacing, relay control, and Blynk communication.

**Libraries Used:**
- `WiFi.h` – to connect ESP32 to Wi-Fi.
- `BlynkSimpleEsp32.h` – to integrate ESP32 with the Blynk IoT platform.
- `Servo.h` – to control the gas valve servo motor.
- `analogRead()` and `digitalWrite()` functions – for sensor reading and device control.

---

### 2. **Blynk IoT Platform**
Blynk Cloud is used to visualize data and send notifications to the user’s smartphone in real time. The app displays gas concentration levels and indicates alert states.

---

### 3. **EasyEDA**
Used for schematic and PCB design. The simulation validates the connection between ESP32, sensors, and actuators before actual hardware implementation.
