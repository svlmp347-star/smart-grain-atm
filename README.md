🌾 GranX: Smart Grain ATM
� � �
Low-cost, open-source automated grain dispenser to make India's PDS transparent, precise, and accessible.
�
Prototype dispensing grains with RFID auth, precise load cell weighing, and LCD feedback.
The Problem
India's Public Distribution System (PDS) serves 800+ million people but loses 30–50% to leakages, manual errors, and corruption (govt estimates). Rural fair price shops face long queues, inaccurate weighing, and fraud — denying rightful rations to the poor.
The Solution: GranX
GranX is a DIY/IoT-powered "Smart Grain ATM" that automates dispensing of rice, wheat, pulses (up to 50kg) with:
Secure authentication (RFID/Aadhaar-compatible)
Industrial-grade precision (load cells)
Real-time cloud logging + offline fallback
Edge AI assistance in local languages (upcoming)
It's a low-cost alternative to proprietary systems like WFP's Annapurti Grain ATM — ideal for small shops, cooperatives, and solar-powered rural setups. Aligned with Digital Agriculture Mission, SMART-PDS, and World's Largest Grain Storage Plan.
Key Features
Authentication — MFRC522 RFID for secure beneficiary verification
Precision Weighing — 50kg S-Type load cell + HX711 (24-bit accuracy)
Dispensing — Dual MG996R servos for controlled release
User Interface — 16x2 I2C LCD + capacitive touch for quantity selection
Connectivity — ESP32 Wi-Fi + Bluetooth (HC-05) for Android monitoring; GSM fallback for no-internet areas
Data & Analytics — Firebase realtime database for transactions, inventory alerts
Edge AI Assistance (Coming Soon) — Offline SLM chatbot (e.g., Phi-2/Gemma) running locally in Termux (Linux environment on Android) for voice/text queries in Hindi/regional languages; no internet needed
Android App (Coming Soon) — Bluetooth-enabled monitoring app for real-time views, alerts, and remote calibration (built with MIT App Inventor or Android Studio)
Power — Low-energy design, solar-ready
Additional Upcoming Enhancements — Integration with Raspberry Pi for advanced AI processing, full vernacular support, AgriStack compatibility, and more robust offline modes
Everything from edge AI (local Termux Linux inference), the Android app, voice support, and expanded integrations is in development and coming soon — stay tuned for updates!
Impact Potential
Reduce leakages by 30%+ through automation & transparency
Faster distribution: 25–50kg in <1 minute vs. manual 10–15 mins
Empower 10,000+ families per 100 units deployed
Supports UN SDGs: Zero Hunger (2), Innovation (9)
INSPIRE MANAK Award Winner — Recognized for innovation in science/tech for social good.
Hardware Bill of Materials (BOM) – Basic Prototype Cost ~₹2,500–3,500
Component
Approx. Cost (INR)
Source/Link Example
ESP32-WROOM-32
300–400
Robu.in / Amazon
RFID-RC522
100–150
Local / Robokits
HX711 + 50kg Load Cell
400–600
Robu.in
MG996R Servo (x2)
400 (total)
Local electronics
16x2 I2C LCD
150
—
HC-05 Bluetooth
200
—
Touch Sensors + Misc
300–500
—
Total (Prototype)
~₹2,500
Excl. chassis/power
Industrial version (~₹10–15k/unit) with aluminum chassis & PCB (thanks to PCBWay sponsorship).
Detailed BOM & Budget for Scaling (Prototype to Pilot – ~₹33,000 Total)
This covers upgrading to industrial-grade chassis, edge AI (RPi), offline capability (GSM), and 5x custom PCBs for testing/multiple units. Aligned with Hack Club Blueprint ask (~$360 USD / ₹33k).
Category
Item
Quantity
Price (INR)
Notes / Vendor Example
Compute
Raspberry Pi 5 (8GB) + Power Supply
1
₹9,500
For edge AI chatbot & advanced processing (Robu.in / Amazon)
Workstation
Refurbished i5/8GB Laptop (for CAD/AI)
1
₹14,500
Design work, model training (local refurb market)
Structure
2040 Aluminium Profiles & Brackets (set)
1 set
₹3,500
Sturdy chassis build
Weight
50kg S-Type Load Cell + HX711
1
₹2,800
High-precision weighing
Valve
MG996R High-Torque Metal Gear Servos
2
₹750
Dispensing mechanism (corrected typo from MG9996R)
Auth
RFID-RC522 + 10 Keycards
1 set
₹600
Secure authentication
Network
SIM800L GSM Module + Antenna
1
₹800
Offline SMS/cloud fallback
PCB
Custom PCB Fabrication & Components
5 units
₹500
Professional boards (PCBWay sponsored base)
Total


₹32,950
~$360 USD – Under Blueprint $400 max
Grand Total Request: ~₹30,000–33,000 (flexible; can optimize by sourcing locally or reusing parts).
Software Architecture
Firmware: Arduino IDE (C++) for ESP32 — src/main.ino
Backend: Python scripts for data sync and AI integration — /python (e.g., offline_chatbot.py using Hugging Face transformers for local SLM inference in Termux)
Mobile: Bluetooth Android app (coming soon) — screenshots/APK in /android
Cloud: Google Firebase (realtime DB + auth)
Edge AI: Local Termux Linux setup on Android/RPi for offline models (coming soon; tested with Phi-2/Gemma)
Installation & Quick Start
Clone repo: git clone https://github.com/svlmp347-star/smart-grain-atm.git
Wire hardware per /schematics/wiring_diagram.pdf (or images in repo)
Calibrate load cell: Upload /src/calibration.ino
Upload main firmware /src/main.ino via Arduino IDE
Set up Firebase: Add project credentials in code
Test: Scan RFID → Select qty → Dispense & verify weight
Detailed guide: /docs/SETUP.md (create if needed). Upcoming: Full Termux setup for edge AI and Android app installation instructions.
Roadmap 2026
Q1 (Current): Prototype refinement with PCBWay sponsorship
Q2 (Post-Boards): Edge AI in Termux Linux + Android app release
Q3: Field pilots (1–5 units in UP villages)
Q4: Scale via grants/incubation
Long-term: Integration with AgriStack / nationwide PDS
Seeking Support (Post-Board Exams – March 2026+)
Student developer (Lucknow, UP) building for real impact. Looking for:
Funding/Grants — ₹5–25 lakhs (prototype to pilot): RKVY-RAFTAAR, SISFS, Pusa Krishi
Hardware — Load cells, servos, Raspberry Pi, solar panels
Mentoring/Incubation — Prototyping help, business guidance
Pilots/Collaboration — With WFP, state PDS depts, cooperatives
Budget Example (for 10-unit pilot): Hardware 40% | Dev/Pilots 40% | Misc 20%
Pitch deck available: Contact for PDF. Open to equity (VCs) or non-dilutive (govt/CSR). Also applying to Hack Club Blueprint for ~₹30k hardware grant.
Contributing
Welcome PRs, issues, suggestions! See /CONTRIBUTING.md (add simple one: report bugs, add docs, test hardware).
License
Apache-2.0 — Free to use, modify, distribute.
Contact
Developer: SuVan (Saurabh Verma), Lucknow, Uttar Pradesh
Email: svlmp347@gmail.com
GitHub: @svlmp347-star
LinkedIn/Twitter: (add if you have)
Acknowledgments: INSPIRE MANAK, PCBWay, open-source libs community.
Thanks for checking out GranX — let's make PDS fairer for rural India! 🚀