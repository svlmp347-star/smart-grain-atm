
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
*The full, detailed Bill of Materials is available as a CSV file: [**BOM.csv**](BOM.csv).* Here are the key components:
## Project Structure & Files