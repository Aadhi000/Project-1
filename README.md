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

![System Architecture](images/BLOCKDIAGRAM.png)

---

## 🔧 Circuit Diagram

![Circuit Diagram](images/CIRCUITDIAGRAM.png)

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
| `Discussions/`               | Contains markdown discussions of system details:                            |
|                              | → `advantages.md` – Benefits and merits of the gas safety system             |
|                              | → `disadvantages.md` – Possible drawbacks or limitations                     |
|                              | → `applications.md` – Areas where the system can be implemented              |
|                              | → `future-scope.md` – Enhancements for future versions                       |
|                                                                                                           |
| `Estimation/`                | Includes project cost, component, and effort analysis                        |
| └── `estimation.md`          | Calculation of total cost and implementation details                         |
|                                                                                                           |
| `Output/`                    | Visual proofs and working system images                                     |
| ├── `images/`                | Snapshots of circuit and working prototype                                  |
| └── `video/`                 | Demonstration video of the gas leakage alert system                         |
|                                                                                                           |
| `Web_Dashboard/`             | Details about IoT dashboard configuration                                   |
| └── `dashboard-description.md` | Explanation of Blynk layout and virtual pin mapping                       |
|                                                                                                           |
| `blynk_credentials/`         | Cloud credentials and configuration files                                   |
| └── `blynk-config.txt`       | Includes template ID, auth token, and event names                           |
|                                                                                                           |
| `docs/`                      | Documentation and technical explanations                                   |
| ├── `architecture.md`        | Describes system’s hardware and software structure                          |
| ├── `working.md`             | Step-by-step explanation of operation                                       |
| └── `literature-survey.md`   | Summarized review of related IoT gas detection systems                      |
|                                                                                                           |
| `extras/`                    | Supplementary project materials                                            |
| └── `REPORT.pdf`             | Complete academic report in PDF format                                      |
|                                                                                                           |
| `firmware/`                  | Source code for ESP32 microcontroller                                      |
| └── `esp32_gas_alert_system.ino` | Firmware implementing gas detection, relay, and IoT alerts          |
|                                                                                                           |
| `flowchart/`                 | System flow representation                                                 |
| └── `flowchart.png`          | Diagram showing logic from detection to alert                              |
|                                                                                                           |
| `images/`                    | Visuals for documentation                                                  |
| ├── `block-diagram.png`      | Functional block diagram of system                                         |
| └── `circuit-diagram.png`    | Circuit schematic for ESP32 + MQ-2 + Relay + Fan + Buzzer setup            |
|                                                                                                           |
| `README.md`                  | You’re reading it — complete overview of the project                        |

---

## 👨‍💻 Developer

- **Aadhi Muhammed**

---

## 🧠 Summary

This project provides a **comprehensive gas safety automation solution** combining hardware detection and cloud-based alerts. It is a reliable and affordable IoT-based approach for residential and industrial applications, preventing accidents by instantly detecting gas leaks, cutting power, and notifying users.
