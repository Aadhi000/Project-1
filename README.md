# 🔥 Remote Controlled Auto Power Trip and Alert System During Gas Leakage

An IoT-based gas leakage detection and alerting solution that monitors the presence of LPG or methane gas in the environment, automatically trips the power supply, and sends alerts through buzzer and Blynk IoT. Built using ESP32, MQ-2 sensor, relay, and motor driver, it provides real-time alerts and prevents fire or explosion hazards.

---

## 🚀 Features

- Real-time detection of gas leakage using MQ-2 sensor  
- Automatic power trip via relay on gas detection  
- Immediate buzzer alarm and exhaust fan activation  
- Blynk IoT cloud integration for remote monitoring and alerts  
- Low-cost, efficient, and user-friendly safety system  

---

## 🧰 Hardware Used

| Component              | Description                                      |
|------------------------|--------------------------------------------------|
| ESP32                  | Main microcontroller with Wi-Fi connectivity     |
| MQ-2 Gas Sensor        | Detects LPG, methane, and propane gas leaks      |
| Relay Module           | Trips main power supply to prevent fire risk     |
| Motor Driver (L298N)   | Controls the exhaust fan for ventilation         |
| Exhaust Fan            | Removes leaked gas from the environment          |
| Buzzer                 | Audible alert during leakage                     |
| Servo Motor            | Automatically closes the gas valve               |

---

## 🖼️ System Architecture

![System Architecture](images/block-diagram.png)

---

## 🔧 Circuit Diagram

![Circuit Diagram](images/circuit-diagram.png)

---

## 🛠️ How It Works

1. The **MQ-2 sensor** continuously monitors gas concentration.  
2. When leakage is detected (above threshold), ESP32 activates:  
   - **Buzzer** to warn users  
   - **Relay** to trip the power supply  
   - **Exhaust fan** to ventilate the gas  
   - **Servo motor** to close the gas valve  
3. Simultaneously, a **Blynk IoT alert** is sent to the user’s smartphone.  
4. Once gas levels drop below safe limits, normal operation resumes automatically.

---

## 💻 Software Stack

- Arduino IDE  
- Blynk IoT Platform  
- EasyEDA (for circuit design and simulation)  

---

## 📂 Repository Structure

| Folder / File                | Description                                                                 |
|------------------------------|-----------------------------------------------------------------------------|
| `firmware/`                  | Contains the Arduino source code for ESP32 microcontroller.                |
| └── `esp32_gas_alert_system.ino` | Firmware handling gas detection, relay control, buzzer, and IoT alerts. |
|                                                                                                           |
| `images/`                    | Includes circuit diagrams, block diagrams, and prototype images.           |
| ├── `block-diagram.png`      | Functional block diagram of the system.                                    |
| ├── `circuit-diagram.png`    | Complete circuit connection schematic.                                     |
| └── `prototype.jpg`          | Photograph of the assembled working project.                              |
|                                                                                                           |
| `docs/`                      | Documentation and supporting materials from the report.                    |
| ├── `abstract.md`            | Abstract of the project.                                                   |
| ├── `hardware.md`            | Description of each hardware component used.                               |
| ├── `software.md`            | Software tools and libraries utilized.                                     |
| ├── `working.md`             | Step-by-step working principle of the project.                             |
| ├── `results.md`             | Output results and system performance.                                     |
| └── `references.md`          | References and citations from the report.                                 |
|                                                                                                           |
| `extras/`                    | Contains the full formatted mini project report.                           |
| └── `REPORT.pdf`             | Final academic report (submitted version).                                |
|                                                                                                           |
| `README.md`                  | Main overview of the project with description, features, and setup guide. |

---

## 👨‍💻 Developer

- **Aadhi Muhammed**

---

## 🧠 Summary

This project provides a **comprehensive gas safety automation solution** combining hardware detection and cloud-based alerts. It is a reliable and affordable IoT-based approach for residential and industrial applications, preventing accidents by instantly detecting gas leaks, cutting power, and notifying users.
