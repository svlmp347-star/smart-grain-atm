# Smart Grain ATM

## Overview

**Smart Grain ATM** is a premium dispensing system that uses RFID cards to authenticate users and dispense grain in precise amounts based on user preferences. Designed for premium users, the system offers secure, personalized, and efficient grain dispensing with a user-friendly interface.

---

## Features

- **RFID Authentication**: Supports **two premium users** (pre-configured) to authenticate and access the system.
- **Personalized Dispensing**: Dispenses grain quantities customized per user.
- **LCD Display**: Interactive user-friendly display for instructions, status, and progress.
- **Feedback Systems**: 
  - LED indicators (Red, Green, Blue)
  - Buzzer sounds for system events (access granted, denied, completed, and more).
- **Auto Shut-off**: Automatically powers off after 2 minutes of inactivity to conserve energy.
- **Touch Sensor Activation**: Activation only via a touch sensor for convenience and security.
- **Servo Motor Control**: Precise grain dispensing using a servo motor.
- **Premium User Tracking**: Tracks the number of times each user accesses the system.

---

## Hardware Used

The following hardware components are part of the **Smart Grain ATM**:

1. **RFID Module (MFRC522)**: Handles card scanning and authentication.
2. **16x2 LCD with I2C Interface (LiquidCrystal_I2C)**: Displays system messages, user names, dispenser status, and instructions.
3. **Servo Motor**: Controls the dispensing gate for grains.
4. **Touch Sensor**: Activates the system and turns the screen on.
5. **LEDs (RGB)**: Indicates various statuses:
   - **Blue** (Blinking): System ready for use
   - **Green**: Access granted or task complete
   - **Red**: Access denied
6. **Buzzer**: Provides audible feedback for different system states.
7. ** ESP32 or Arduino Board**: Main controller running the software logic.

---

## Repositories

You can access the source code and relevant files [here](https://github.com/svlmp347-star/smart-grain-atm).

---

## Supported Users

The system supports only **two predefined premium users** for now! Each user is associated with:
- A unique RFID card UID
- User name
- Pre-defined grain quantity (grams) and dispensing time (seconds)

| User Name | Card UID       | Grain (grams) | Dispense (seconds) |
|-----------|--------------- |---------------|---------------------|
| KANIKKA   | `0x73E245FB`   | 100           | 3 seconds          |
| MOHIT     | `0x539C41FB`   | 200           | 6 seconds          |

---

## Software Logic and Control Flow

### 1. **Initial Setup**
- The system remains off until activated via the **Touch Sensor**.
- Upon activation:
  - The system powers on the LCD.
  - LEDs start blinking blue indicating readiness.

### 2. **Card Scanning and Authentication**
- Users scan their RFID cards.
- If the card matches a **premium user**:
  - The system greets the user with a personalized message.
  - Dispenses predefined grain quantities.
- Otherwise:
  - Access is **Denied** with red light and error sound.

### 3. **Dispensing Process**
- Opens the gate controlled via the **servo motor**.
- Displays remaining dispensing time live on the LCD.
- Buzzer feedback indicates the start and end of the dispensing.

### 4. **Timeouts and Auto-Shutdown**
- After 2 minutes of inactivity:
  - The system powers down the LCD and LEDs.
  - Resets to standby mode until reactivated.

---

## Component Wiring

| Pin/Components         | Arduino Pin  |
|-------------------------|--------------|
| RFID Reset (RST)        | 9            |
| RFID SS                 | 10           |
| Touch Sensor            | 2            |
| Buzzer                  | 4            |
| Servo Motor             | 5            |
| Red LED                 | 6            |
| Green LED               | 7            |
| Blue LED                | 8            |

---

## Usage Guide

1. **Initial Startup**:
   - Connect the components as described above.
   - Power up the Arduino board.
   - Touch the sensor to activate the system.

2. **Card Access**:
   - Place the premium RFID card near the scanner.
   - Wait for the LCD to display the welcome message.
   - Collect the pre-measured grain when the dispensing completes.

3. **System Shutdown**:
   The system automatically powers off if no card is scanned for 2 minutes.

---

## Code Highlights

1. **Premium Users**: Defined in a struct format for easy expandability.
   ```cpp
   struct User {
       byte uid[4];
       const char* name;
       int grams;
       int seconds;
       int usageCount;
   };
   ```

2. **Dispensing Timer**:
   ```cpp
   void handleDispensing() {
       unsigned long currentTime = millis();
       unsigned long elapsed = (currentTime - dispenseStartTime) / 1000;
       int remaining = dispenseSeconds - elapsed;
       // Timer updates on LCD
   }
   ```

3. **Access Denial**:
   ```cpp
   void premiumAccessDenied() {
       rgbRed(); // Turn LED Red
       lcd.print("ACCESS DENIED"); // Display Message
       tone(buzzerPin, 400, 800); // Error Sound
   }
   ```

---

## Future Scope

- mobile based delivery system 
- solar addition
- Enhanced security with dynamic user addition.
- Expand to dispensing multiple grain types.

---

## License

This project is released under the [apache】(LICENSE).

---

## Credits

This project was developed by **svlmp347-star**. Contributions and feedback are welcome! Feel free to create a pull request on GitHub or open an issue.
