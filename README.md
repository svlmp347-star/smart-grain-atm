# 🌾 GranX: Smart Grain ATM (Project GranX)
**An IoT & Edge-AI solution to eliminate corruption and measurement fraud in rural India's PDS.**

[![Project Status: Active](https://img.shields.io/badge/Project%20Status-Active-brightgreen)](https://github.com/Svlmp347-star/smart-grain-atm)
[![Award: INSPIRE MANAK](https://img.shields.io/badge/Award-District%20Winner-gold)](https://www.inspireawards-dst.gov.in/)
[![Sponsor: PCBWay](https://img.shields.io/badge/Sponsor-PCBWay-orange)](https://www.pcbway.com)

---

## 📖 Overview
GranX (Smart Grain ATM) is an automated distribution system designed to modernize the Public Distribution System (PDS) in India. By replacing manual weighing with **precision load cells** and human logs with **RFID authentication**, we ensure 100% transparency in grain distribution for rural communities.

## 🚀 Key Features
- **Precision Dispensing:** Uses 24-bit HX711 digitization for industrial-grade weight accuracy.
- **Smart Authentication:** Secure RFID-RC522 identity verification to prevent ration theft.
- **Edge Intelligence (Upcoming):** Integrating **Small Language Models (SLMs)** for offline, vernacular voice-assistance (currently tested in Termux).
- **Cloud Analytics:** Real-time transaction logging to **Google Firebase** via ESP32.
- **Resilient Connectivity:** Designed to operate in zero-internet zones using a dual-path Wi-Fi/GSM architecture.

## 🛠️ Tech Stack
| Component | Technology |
| :--- | :--- |
| **Control** | ESP32-WROOM-32 / Arduino IDE |
| **Sensing** | S-Type Load Cell + HX711 ADC |
| **Interface** | I2C LCD / RFID-RC522 / Touch Sensors |
| **Actuation** | MG996R Metal Gear Servos |
| **Backend** | Google Firebase / Python (Data Sync) |
| **OS Support** | Linux/Termux (for Edge AI Research) |

---

## 📅 Roadmap 2026
- [x] **District Level Success:** Won the INSPIRE MANAK Award.
- [ ] **Phase 2 (Current):** Transitioning from breadboard to an **Aluminium T-Slot Chassis** and professional PCB (Sponsored by **PCBWay**).
- [ ] **Grant Milestone:** Applying for **Hack Club Blueprint** to fund industrial S-type load cells and Raspberry Pi for local SLM hosting.
- [ ] **Phase 3 (April):** Deployment of field-ready pilot for **Pusa Krishi (ICAR-IARI)** grant application.

---

## 📂 Repository Structure
- `/src`: ESP32 Firmware (Arduino C++)
- `/python`: Backend scripts for database management and AI inference testing.
- `/schematics`: PCB design files and wiring diagrams.

## 🤝 Contribution & Support
I am a student developer based in **Lakhimpur, Uttar Pradesh**, working to solve local problems through global technology. I am currently seeking mentorship and hardware support to finalize the industrial prototype.

**Developer:** Saurabh Verma  
**GitHub:** [@svlmp347-star](https://github.com/svlmp347-star)
