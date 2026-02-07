#pragma once

#include <Arduino.h>

// === Pin Mapping ===
const int touchPin = 2;
const int buzzerPin = 4;
const int servoPin = 5;
const int redPin = 6;
const int greenPin = 7;
const int bluePin = 8;

// === RFID Pins ===
#define RST_PIN 9
#define SS_PIN 10

// === User Configuration ===
struct User {
  byte uid[4];
  const char* name;
  int grams;
  int seconds;
  int usageCount;
};

// Add or edit users here. UID bytes must match your RFID cards.
User users[] = {
  {{0x73, 0xE2, 0x45, 0xFB}, "KANIKKA", 100, 3, 0},
  {{0x53, 0x9C, 0x41, 0xFB}, "MOHIT", 150, 4, 0}
};

const int numUsers = sizeof(users) / sizeof(users[0]);
const byte uidSize = 4;
