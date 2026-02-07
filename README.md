
# GranX: The Smart Grain ATM

### **A Hardware Solution to Bring Transparency to India's Ration Shops**

[![Blueprint](https://img.shields.io/badge/Hack%20Club-Blueprint-ec3750.svg)](https://blueprint.hackclub.com)

## What is this?

GranX is a "Grain ATM"—a hardware device that automates and verifies the distribution of food grains (like rice, wheat, or pulses) at government ration shops in India. It uses an RFID card for identification, a precise load cell to weigh the dispensed grain, and an ESP32 microcontroller to log every transaction digitally to the cloud. The core idea is simple: **the weight leaving the machine must match the weight recorded in the digital ledger**, leaving no room for manipulation or "leakage."

**Key Features:**
*   **RFID-Based Authentication:** Users authenticate with their ration card.
*   **Precise, Verified Dispensing:** A load cell measures grain weight in real-time as a servo-controlled gate releases it.
*   **IoT Transparency:** Every transaction (user ID, grain type, weight, time) is sent to a Firebase database via WiFi.
*   **Offline-First Design:** Includes a local Bluetooth app for shops with poor internet and plans for an offline AI assistant.
*   **Built for Scale:** Designed to handle sacks of grain up to 50kg.

## Why did I make it? (The Real Story)

I built this because I've seen the problem with my own eyes. Where I live in Lakhimpur Kheri, the Public Distribution System (PDS) is a lifeline for many families. But too often, people come back from the ration shop with less grain than their entitlement. They talk about "leakage" and suspect the scale is wrong, but they have no proof—it's their word against a handwritten ledger.

This isn't just a technical problem; it's a social injustice. My motivation isn't just to build a cool gadget. It's to build a **"trust machine."** I wanted to create a simple piece of hardware that could stand in the shop and be an impartial witness, ensuring that what the government allocates is exactly what reaches people's bags. Winning the District INSPIRE MANAK Award for this idea showed me that others believed in this vision for change, too.

## How does it work? (In Simple Terms)

1.  **Identify:** A beneficiary taps their RFID-based ration card on the reader.
2.  **Select:** They choose the grain type and quantity via a simple interface (button/LCD/Bluetooth app).
3.  **Dispense & Verify:** The microcontroller opens a servo gate. As grain flows out, the load cell constantly measures its weight. The gate closes *exactly* when the target weight is reached.
4.  **Log & Sync:** The ESP32 records the transaction with a timestamp and immediately pushes this data to a secure online database (Firebase), creating a permanent, tamper-proof record.

## 📸 Visual Journey

### The First Prototype
![My first working prototype on a breadboard](https://github.com/Svlmp347-star/smart-grain-atm/blob/main/Real%20images%20of%20prototype?raw=true)
*A mess of wires, but the moment the load cell reading matched the weight on my kitchen scale was pure magic.*

### The Guts of the Machine
![All major components laid out](https://github.com/Svlmp347-star/smart-grain-atm/blob/main/Components.jpg?raw=true)
*The core team: ESP32, RFID reader, load cell, servo motor, and motor driver. Seeing it all come together off the breadboard was a huge step.*

### Recognition 
*This award was a validation that the problem I was trying to solve was real and important.*

## Bill of Materials (BOM)
The full, detailed Bill of Materials is available as a CSV file: [**BOM.csv**](BOM.csv).

**Highlights from the BOM:**
- ESP32-S3 DevKitC-1 (WiFi/BLE)
- 50kg load cell + HX711 amplifier
- PN532 RFID/NFC module
- NEMA 17 stepper motor + A4988 driver
- 0.96" OLED display

## Project Structure & Files
```
.
├── Main source code .ino          # Arduino sketch for RFID + LCD + servo workflow
├── config.h                       # Pin map + user configuration
├── BOM.csv                        # Bill of Materials
├── README.md                      # Project overview and setup
├── LICENSE
├── Components.jpg                 # Key hardware parts laid out
├── Servomotor.jpg
├── Smart-grain-atm image.jpg
├── Androidapp.jpg
└── Real images of prototype/      # Prototype images
```

## Hardware & Wiring Notes
This repository includes both **current prototype firmware** (Arduino sketch) and a **next-iteration BOM**. The BOM reflects newer parts than the current sketch, so treat it as forward-looking.

### Current Prototype (matches the sketch)
The existing sketch targets an ESP32/Arduino-class MCU with RFID, LCD, a load cell, and a servo gate. Typical wiring for the current sketch:
- **RFID (MFRC522)**: `RST_PIN=9`, `SS_PIN=10` (SPI)
- **Touch sensor**: `touchPin=2`
- **Buzzer**: `buzzerPin=4`
- **Servo**: `servoPin=5`
- **RGB LED**: `redPin=6`, `greenPin=7`, `bluePin=8`
- **LCD (I2C)**: address `0x27` (16x2)

> Update the pin map in the sketch if you use a different board or wiring layout.

### Next Iteration (matches the BOM)
The BOM targets a more robust prototype with PN532 RFID, a stepper motor gate, and an OLED display. If you build with those parts, you will need to update the firmware accordingly.

## Firmware Setup
1. **Install the Arduino IDE** (or PlatformIO).
2. **Install libraries**:
   - `MFRC522`
   - `Servo`
   - `LiquidCrystal_I2C`
3. **Open** `Main source code .ino` and select your board/port.
4. **Update** `config.h` with your pin mapping and user list.
5. **Upload** the sketch.

## Calibration & Tuning (Recommended)
To make dispensing accurate and repeatable:
- **Load cell calibration**: Use a known weight to calibrate scale readings.
- **Servo timing vs. grams**: Measure actual grams dispensed for a fixed time and adjust `grams` and `seconds` per user accordingly.
- **Flow rate variance**: Different grains flow differently. Keep a small lookup table if you want multi-grain support.

## Usage Flow
1. **Touch** the sensor to wake the system.
2. **Scan** a registered RFID card.
3. **Dispense** starts automatically and stops after the configured time.
4. **Collect** grain and wait for the ready screen.

## Safety & Maintenance
- Disconnect power before servicing motors, wiring, or the load cell.
- Secure all wiring to avoid grain dust buildup or shorts.
- Calibrate the load cell after any mechanical changes.

## Configuration
User configuration now lives in `config.h`, including RFID UIDs, names, and dispense settings:
```cpp
User users[] = {
  {{0x73, 0xE2, 0x45, 0xFB}, "KANIKKA", 100, 3, 0},
  {{0x53, 0x9C, 0x41, 0xFB}, "MOHIT", 150, 4, 0}
};
```
For scaling, consider moving this to a runtime config (SPIFFS/LittleFS) or adding an admin setup mode.

## Status
- **Prototype firmware**: Functional for RFID + LCD + servo flow.
- **BOM**: Captures a next-iteration hardware upgrade (stepper + OLED + PN532).

## Roadmap
- Add a calibration workflow for load cell + dispensing.
- Add admin card registration and quota setup.
- Add offline transaction queueing + sync to Firebase when online.
- Document Firebase schema and sample payloads.

## Contributing
Issues and improvements are welcome. Please open a PR with clear test details or a short demo video for hardware behavior changes.

## License
See [LICENSE](LICENSE).
