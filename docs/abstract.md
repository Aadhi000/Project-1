# 🔍 Abstract

The **Remote Controlled Auto Power Trip and Alert System During Gas Leakage** is an IoT-based project designed to detect gas leakage and take immediate preventive action to avoid accidents. 

It uses an **ESP32 microcontroller**, **MQ-2 gas sensor**, **relay module**, **buzzer**, and **exhaust fan** to ensure safety during LPG or methane leaks. When the MQ-2 sensor detects a concentration level above the safety threshold, the ESP32 automatically:

- Trips the power supply using a relay.
- Activates a buzzer to alert users.
- Turns ON the exhaust fan for ventilation.
- Sends a remote notification via the **Blynk IoT platform**.

The system resets itself automatically once the gas level becomes normal. This low-cost and reliable design is suitable for homes, restaurants, and industrial environments where gas is commonly used.
