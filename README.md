# 🌾 GranX: Smart Grain ATM (Project GranX)
**An IoT-enabled, AI-assisted autonomous dispensing system designed to eliminate PDS corruption in rural India.**

[![Status](https://img.shields.io/badge/Project--Phase-Industrial--Prototyping-blue)](https://github.com/Svlmp347-star/smart-grain-atm)
[![Award](https://img.shields.io/badge/Recognition-District%20INSPIRE%20Winner-gold)](https://www.inspireawards-dst.gov.in/)
[![Hardware](https://img.shields.io/badge/Compute-ESP32%20%7C%20Edge%20AI-orange)](https://github.com/Svlmp347-star/smart-grain-atm)

---

## 📖 Overview
GranX addresses the "Leakage" problem in the Indian Public Distribution System (PDS). By automating grain weighing and dispensing using **Load Cells** and **RFID Authentication**, we remove human interference, ensuring that every gram of food grain reaches the rightful beneficiary.

### **The Innovation: Offline Edge Intelligence**
Rural connectivity is unstable. GranX is unique because it integrates **Small Language Models (SLM)** locally. This allows for:
- **Vernacular Voice UI:** Non-literate users can interact via Hindi/Local dialects.
- **Zero-Internet Reliability:** All authentication and weighing logic happens on the device (Edge), with **GSM (SIM800L)** acting as a low-bandwidth sync to Firebase.

---

## 🛠️ Technical Architecture


### **Current Hardware Implementation**
- **Microcontroller:** ESP32-WROOM-32 (Handling multi-threading for sensors and WiFi/GSM).
- **Sensing:** 24-bit HX711 ADC with 50kg S-Type Industrial Load Cells.
- **Security:** RFID-RC522 for encrypted UID-based beneficiary tracking.
- **Actuation:** High-torque MG996R Metal Gear Servos for precision hopper control.
- **Connectivity:** Dual-path Firebase integration (Wi-Fi + SIM800L GSM).

### **Edge-AI Development (The "Mobile-First" Hacker Approach)**
Due to hardware constraints, I have pioneered an optimized development workflow:
- **Quantization:** Testing 4-bit quantized SLMs (TinyLlama/Phi-2) using **Termux/Linux** environments on mobile ARM architecture.
- **Deployment:** Transitioning these validated models to **Raspberry Pi 5** for the 2026 pilot.

---

## 📂 Project Structure
- `/src`: Core ESP32 Arduino/C++ firmware for sensor integration.
- `/python`: Edge-AI scripts and SLM inference wrappers.
- `/docs`: Schematics, wiring diagrams, and INSPIRE Award documentation.
- `/research`: Benchmarks for offline AI performance on ARM-based edge nodes.

---

## 🏆 Recognition & Support
- **District Level Winner:** INSPIRE MANAK Award (DST, Govt. of India).
- **Manufacturing Sponsor:** Professional PCB fabrication support from **PCBWay**.
- **Candidate:** Hack Club Blueprint Grant 2026.

---

## 📅 Roadmap to 2026
- **Q1 (Jan-Feb):** Finalizing the Aluminium T-Slot chassis and industrial load cell calibration.
- **Q2 (April):** Application for the **Pusa Krishi (ICAR-IARI)** Student Grant-in-Aid (₹4 Lakhs).
- **Q3 (July):** First on-ground pilot deployment in **Lakhimpur, Uttar Pradesh**.

---

**Developed with 💡 by Saurabh Verma** *Building technology to solve the "last-mile" transparency gap.*
