# GranX: Smart Grain ATM
**Hardware-based transparency for the Indian Public Distribution System (PDS).**

Built by Saurabh Verma (District Winner, INSPIRE MANAK Awards).

## 🛠️ The Problem & Solution
In my district (Lakhimpur Kheri), grain leakage at ration shops is a major issue. GranX is a hardware-verified dispensing system that ensures the weight a citizen receives matches the digital record.

## 🏗️ Hardware Architecture
* **Brain:** ESP32 DevKit V1
* **Sensing:** 20kg Load Cell with HX711 Amplifier (Precision: ±5g)
* **Dispensing:** High-Torque MG996R Servo (Metal Gear) for the gate mechanism
* **Communication:** Local WebServer for offline data logging via Termux

## 📂 Project Structure
* [`/src`](./src): Contains `main.ino` for the weight logic and gate control.
* [`/schematics`](./schematics): PDF of the breadboard wiring and power distribution.
* [`/CAD`](./CAD): .STL files for the 3D-printed grain funnel and servo mount.

## 🚀 Quick Start (For Developers)
1. **Calibration:** Upload `src/calibration.ino` to find your load cell's scale factor.
2. **Setup:** Update `WIFI_SSID` in `main.ino` to connect to your local Termux node.
3. **Assembly:** Mount the load cell under the grain bucket and connect the Servo to Pin 18.



## 📊 Current Progress
- [x] Basic weight sensing logic
- [x] Servo-gate prototype
- [ ] Industrial metal chassis (Phase 2 - Funding required)
- [ ] Biometric integration

---
*This project is an open-source initiative to improve food security in rural India.*
