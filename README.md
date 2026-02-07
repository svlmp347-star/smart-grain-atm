---

<p align="center">
  <img src="assets/logo.svg" width="400" alt="Smart Grain ATM - GranX Logo"/>
</p>

# Smart Grain ATM (GranX)

GranX is a "Grain ATM"—a hardware device that automates and verifies the distribution of subsidized grain to recipients via RFID authentication, real-time weighing, and tamper-evident cloud logging.

> **Winner, District INSPIRE MANAK Award**

---

## Motivation
Where I live in Lakhimpur Kheri, the Public Distribution System (PDS) is a lifeline for many families. But too often, people come back from the ration shop with less grain than their entitlement. Without proof, it's their word against a handwritten ledger. GranX serves as a **"trust machine"**—an impartial witness ensuring the government’s allocation is delivered to its recipients.

---

## How does it work? (In Simple Terms)

<p align="center">
  <img src="assets/workflow.svg" width="620" alt="GranX Workflow: Identify → Select → Dispense & Verify → Log & Sync"/>
</p>

1. **Identify:** Beneficiary taps their RFID ration card on the reader.
2. **Select:** They choose the grain type and quantity via a simple interface (button, LCD, or Bluetooth app).
3. **Dispense & Verify:** The microcontroller opens a gate; the load cell measures flow and closes the gate at the precise target weight.
4. **Log & Sync:** ESP32 records the transaction and syncs it to a secure database (Firebase), ensuring a tamper-proof log.

---

## 📸 Visual Journey

### The First Prototype
![Prototype Breadboard](https://github.com/Svlmp347-star/smart-grain-atm/blob/main/Real%20images%20of%20prototype?raw=true)
*A mess of wires, but when the load cell reading matched my kitchen scale, it was magic!*

### The Guts of the Machine
![Components](https://github.com/Svlmp347-star/smart-grain-atm/blob/main/Components.jpg?raw=true)
*ESP32, RFID reader, load cell, servo motor, and driver coming together off the breadboard.*

### Recognition
*This award was validation that the problem is real—and solvable.*

---

## Bill of Materials (BOM)
The full, detailed Bill of Materials is available as a CSV file: [**BOM.csv**](BOM.csv).

**Highlights from the BOM:**
- ESP32-S3 DevKitC-1 (WiFi/BLE)
- 50kg load cell + HX711 amplifier
- PN532 RFID/NFC module
- NEMA 17 stepper motor + A4988 driver
- 0.96" OLED display

---

## Project Structure & Files
```
.
├── Main source code .ino      # Arduino firmware
├── BOM.csv                   # Bill of Materials
├── README.md
├── LICENSE
├── assets/
│   ├── logo.svg              # Project logo/banner
│   └── workflow.svg          # Visual workflow diagram
├── Components.jpg
├── Servomotor.jpg
├── Smart-grain-atm image.jpg
├── Androidapp.jpg
└── Real images of prototype/ # Prototype images
```
---

## Hardware & Wiring Notes

- Current prototype: Uses MFRC522 RFID, servo, load cell, 16x2 I2C LCD, basic GPIOs (see wiring diagram & code).
- Next iteration: BOM supports PN532 RFID, stepper gate, OLED—update firmware accordingly.

---

## Firmware Setup

1. Install Arduino IDE or PlatformIO.
2. Install libraries:
   - `MFRC522`
   - `Servo`
   - `LiquidCrystal_I2C`
3. Open the main sketch, select your board/port, upload.

---

## Calibration & Tuning

- Calibrate load cell with a known weight.
- Tune grams per open-time in code per grain type.
- Use the lookup table for different grain flows.

---

## Usage Flow

1. Touch sensor wakes system.
2. Scan RFID card.
3. Dispensing starts and stops automatically.
4. Collect grain—ready for next user.

---

## Safety & Maintenance

- Disconnect power before servicing.
- Secure wiring, keep free of dust.
- Recalibrate after mechanical changes.

---

## Configuration

Example hardcoded users:
```cpp
User users[] = {
  {{0x73, 0xE2, 0x45, 0xFB}, "KANIKKA", 100, 3, 0},
  {{0x53, 0x9C, 0x41, 0xFB}, "MOHIT", 150, 4, 0}
};
```
For scale, move configs to SPIFFS/LittleFS, or add an admin setup mode.

---

## Status

- Prototype is functional.
- BOM and docs point toward next iteration.

## Roadmap

- Add calibration workflow.
- Admin registration/quota setting.
- Offline queueing and Firebase sync.
- Full database/schema docs.

## Contributing

PRs and issues welcome, demos encouraged for hardware behavior changes.

## License

See [LICENSE](LICENSE).

---

### [assets/logo.svg](assets/logo.svg) | [assets/workflow.svg](assets/workflow.svg)