#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// RFID pins
#define RST_PIN 9
#define SS_PIN 10
MFRC522 mfrc522(SS_PIN, RST_PIN);

// Devices & pins
const int touchPin = 2;
const int buzzerPin = 4;
const int servoPin = 5;
const int redPin = 6;
const int greenPin = 7;
const int bluePin = 8;

Servo myServo;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Single LCD

// Timeouts
const unsigned long AUTO_OFF_MS = 2UL * 60UL * 1000UL; // 2 minutes
unsigned long lastActivity = 0;
bool systemOn = false;
bool dispensing = false;
unsigned long dispenseStartTime = 0;
int dispenseSeconds = 0;
unsigned long lastBlink = 0;
bool blinkState = false;

// ONLY 2 CARDS - Premium Users
struct User {
  byte uid[4];
  const char* name;
  int grams;
  int seconds;
  int usageCount;
};

User users[] = {
  {{0x73, 0xE2, 0x45, 0xFB}, "KANIKKA", 100, 3, 0},  // Card 1
  {{0x53, 0x9C, 0x41, 0xFB}, "MOHIT", 150, 4, 0}     // Card 2
};

const int numUsers = 2;
byte uidSize = 4;
User* currentUser = nullptr;

void setup() {
  Serial.begin(9600);
  
  // Initialize pins
  pinMode(touchPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Initialize outputs - ALL OFF at startup
  digitalWrite(buzzerPin, LOW);
  rgbOff();

  // Initialize servo
  myServo.attach(servoPin);
  myServo.write(0); // Close position

  // Initialize LCD but TURN IT OFF initially
  lcd.init();
  lcd.noBacklight(); // SCREEN STARTS OFF

  // Initialize RFID
  SPI.begin();
  mfrc522.PCD_Init();

  Serial.println("PREMIUM GRAIN ATM - READY");
  Serial.println("SCREEN: OFF - Touch sensor to activate");
}

void loop() {
  // Handle blue LED blinking when system is ON
  if (systemOn && !dispensing) {
    handleBlueBlink();
  }

  // Handle dispensing timer
  if (dispensing) {
    handleDispensing();
    return;
  }

  // Touch sensor to start system - ONLY WAY TO ACTIVATE
  if (!systemOn) {
    if (digitalRead(touchPin) == HIGH) {
      delay(30); // Premium debounce
      if (digitalRead(touchPin) == HIGH) {
        activatePremiumSystem();
      }
    }
    return;
  }

  // Auto-off after 2 minutes inactivity
  if (millis() - lastActivity >= AUTO_OFF_MS) {
    premiumShutdown();
    return;
  }

  // RFID check
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    lastActivity = millis();
    handlePremiumCardScan();
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  }
}

void handleBlueBlink() {
  // ULTRA FAST BLINKING - 100ms intervals
  if (millis() - lastBlink >= 100) {
    lastBlink = millis();
    blinkState = !blinkState;
    digitalWrite(bluePin, blinkState ? HIGH : LOW);
  }
}

void handlePremiumCardScan() {
  byte *uid = mfrc522.uid.uidByte;
  byte scanSize = mfrc522.uid.size;

  Serial.print("Premium Card Scan: ");
  for (byte i = 0; i < scanSize; i++) {
    Serial.print(uid[i] < 0x10 ? " 0" : " ");
    Serial.print(uid[i], HEX);
  }
  Serial.println();

  // Check against EXCLUSIVE 2 users only
  currentUser = nullptr;
  for (int i = 0; i < numUsers; i++) {
    if (compareUid(uid, scanSize, users[i].uid, uidSize)) {
      currentUser = &users[i];
      currentUser->usageCount++;
      Serial.print("ACCESS GRANTED: ");
      Serial.println(currentUser->name);
      break;
    }
  }

  if (currentUser != nullptr) {
    premiumAccessGranted();
  } else {
    premiumAccessDenied();
  }
}

void premiumAccessGranted() {
  // STOP BLINKING - Solid green for access
  digitalWrite(bluePin, LOW);
  rgbGreen();
  
  // Premium welcome sound
  tone(buzzerPin, 1800, 200);
  delay(300);
  
  // WELCOME SCREEN
  lcd.clear();
  lcd.print(" SMART GRAIN ATM");
  lcd.setCursor(0, 1);
  lcd.print("   WELCOME :)   ");
  delay(2000);

  // PERSONALIZED GREETING
  lcd.clear();
  lcd.print("HELLO ");
  lcd.print(currentUser->name);
  lcd.setCursor(0, 1);
  lcd.print("USER #");
  lcd.print(currentUser->usageCount);
  delay(2500);

  // TRANSACTION DETAILS
  lcd.clear();
  lcd.print("DISPENSING:");
  lcd.setCursor(0, 1);
  lcd.print(currentUser->grams);
  lcd.print("g IN ");
  lcd.print(currentUser->seconds);
  lcd.print("s");
  delay(2000);

  // START PREMIUM DISPENSING
  startPremiumDispensing();
}

void startPremiumDispensing() {
  dispensing = true;
  dispenseStartTime = millis();
  dispenseSeconds = currentUser->seconds;
  
  // SOLID BLUE during dispensing
  rgbBlue();
  
  lcd.clear();
  lcd.print("PROCESSING...");
  lcd.setCursor(0, 1);
  lcd.print("TIME: ");
  lcd.print(dispenseSeconds);
  lcd.print("s REMAINING");
  
  // Processing sound
  tone(buzzerPin, 1200, 100);
  myServo.write(90); // Open dispense
}

void handleDispensing() {
  unsigned long currentTime = millis();
  unsigned long elapsed = (currentTime - dispenseStartTime) / 1000;
  int remaining = dispenseSeconds - elapsed;
  
  // Update timer every second
  static unsigned long lastUpdate = 0;
  if (currentTime - lastUpdate >= 1000) {
    lastUpdate = currentTime;
    lcd.setCursor(6, 1);
    lcd.print("  ");
    lcd.setCursor(6, 1);
    lcd.print(remaining);
  }
  
  // Check if dispensing complete
  if (currentTime - dispenseStartTime >= dispenseSeconds * 1000UL) {
    finishPremiumDispensing();
  }
}

void finishPremiumDispensing() {
  dispensing = false;
  myServo.write(0); // Close dispense
  
  // SUCCESS SOUND
  tone(buzzerPin, 2000, 500);
  
  // THANK YOU SCREEN
  lcd.clear();
  lcd.print("  TRANSACTION");
  lcd.setCursor(0, 1);
  lcd.print("   COMPLETED!   ");
  rgbGreen();
  delay(2000);

  // COLLECTION MESSAGE
  lcd.clear();
  lcd.print(" PLEASE COLLECT");
  lcd.setCursor(0, 1);
  lcd.print("  YOUR GRAIN  ");
  delay(2000);

  // RETURN TO READY STATE
  lcd.clear();
  lcd.print(" SMART GRAIN ATM");
  lcd.setCursor(0, 1);
  lcd.print(" SCAN CARD -->  ");
  
  // RESTART ULTRA FAST BLINKING
  lastActivity = millis();
  lastBlink = millis();
  blinkState = true;
}

void premiumAccessDenied() {
  // ACCESS DENIED SEQUENCE
  rgbRed();
  
  // Error sound
  tone(buzzerPin, 400, 800);
  
  lcd.clear();
  lcd.print("  ACCESS DENIED");
  lcd.setCursor(0, 1);
  lcd.print("INVALID CARD :(");
  delay(2500);

  // RETURN TO READY
  lcd.clear();
  lcd.print(" SMART GRAIN ATM");
  lcd.setCursor(0, 1);
  lcd.print(" SCAN CARD -->  ");
  
  // RESTART ULTRA FAST BLINKING
  lastActivity = millis();
  lastBlink = millis();
  blinkState = true;
}

void activatePremiumSystem() {
  systemOn = true;
  lastActivity = millis();
  lastBlink = millis();
  blinkState = true;
  
  // TURN ON THE SCREEN!
  lcd.backlight();
  
  Serial.println("PREMIUM SYSTEM ACTIVATED - SCREEN ON");
  
  // Activation sound
  tone(buzzerPin, 1500, 300);
  
  // START ULTRA FAST BLINKING IMMEDIATELY
  lcd.clear();
  lcd.print(" SMART GRAIN ATM");
  lcd.setCursor(0, 1);
  lcd.print("  WELCOME :)    ");
  delay(1500);
  
  // READY FOR CARDS
  lcd.clear();
  lcd.print(" SMART GRAIN ATM");
  lcd.setCursor(0, 1);
  lcd.print(" SCAN CARD -->  ");
  
  Serial.println("ULTRA FAST BLINKING STARTED");
  Serial.println("READY FOR PREMIUM CARDS");
}

void premiumShutdown() {
  systemOn = false;
  dispensing = false;
  currentUser = nullptr;
  
  Serial.println("PREMIUM SHUTDOWN - 2min timeout");
  
  // Shutdown sound
  tone(buzzerPin, 800, 200);
  
  // SHUTDOWN MESSAGE
  lcd.clear();
  lcd.print("  SYSTEM SLEEP");
  lcd.setCursor(0, 1);
  lcd.print("  TOUCH TO WAKE ");
  delay(2000);
  
  // TURN OFF ALL LIGHTS AND SCREEN!
  rgbOff();
  lcd.noBacklight(); // TURN SCREEN OFF
  myServo.write(0);
  
  Serial.println("SCREEN: OFF - System in standby");
}

// ===== PREMIUM LED CONTROL =====
void rgbOff() {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}

void rgbRed() {
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}

void rgbGreen() {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, LOW);
}

void rgbBlue() {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, HIGH);
}

// ===== SECURITY FUNCTION =====
bool compareUid(byte *a, byte aSize, byte *b, byte bSize) {
  if (aSize != bSize) return false;
  for (byte i = 0; i < aSize; i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}
