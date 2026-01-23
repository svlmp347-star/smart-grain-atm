# GranX: Smart Grain ATM
**Hardware-based transparency for the Indian Public Distribution System (PDS).**

Built by Saurabh Verma (District Winner, INSPIRE MANAK Awards).

## 🛠️ The Problem & Solution
In my district (Lakhimpur Kheri), grain leakage at ration shops is a major issue. GranX is a hardware-verified dispensing system that ensures the weight a citizen receives matches the digital record.

smart-grain-atm/
│
├── firmware/
│   └── main.ino
│
├── hardware/
│   ├── cad/
│   │   └── granx.step
│   └── schematics/
│       └── wiring_diagram.png
│
├── docs/
│   ├── photos/
│   │   └── prototype.jpg
│   └── cad/
│       └── granx_model.png
│
├── BOM.csv
└── README.md

## 🏗️ Hardware Architecture
* **Brain:** ESP32 DevKit V1
* **Sensing:** 20kg Load Cell with HX711 Amplifier (Precision: ±5g)
* **Dispensing:** High-Torque MG996R Servo (Metal Gear) for the gate mechanism
* **Communication:** Bluetooth, wifi, LiquidCrystal_I2C Displays 
Touch screen Displays 



## 📊 Current Progress
- [x] Basic weight sensing logic
- [x] Servo-gate prototype
- [ ] Industrial metal chassis (Phase 2 - Funding required)
- [ ] Biometric integration

---
*This project is an open-source initiative to improve food security in rural India.*
