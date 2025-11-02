# ⚡ Working Principle

The system continuously monitors gas concentration through the **MQ-2 sensor**. The ESP32 reads the sensor’s analog output and compares it with a predefined threshold value.

### Step-by-Step Operation:
1. **Initialization** – ESP32 connects to Wi-Fi and initializes all peripherals.
2. **Gas Detection** – MQ-2 senses gas concentration in ppm (parts per million).
3. **Threshold Check** – If gas level exceeds the threshold:
   - The **relay** module disconnects the power supply.
   - The **buzzer** is turned ON for an audible alarm.
   - The **exhaust fan** is activated for ventilation.
   - The **servo motor** closes the gas valve.
   - A **Blynk IoT alert** is sent to the user’s smartphone.
4. **Normal Condition** – When gas concentration drops below the threshold:
   - Power supply is restored.
   - Buzzer and fan are turned OFF.
   - System returns to standby mode.

This automated detection and response ensure that hazardous gas leaks are quickly neutralized without manual intervention.
