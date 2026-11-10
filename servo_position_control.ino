#include <Servo.h>
#include <LiquidCrystal.h>

// --- Button Pins ---
const uint8_t BUTTON_UP_PIN = 2;
const uint8_t BUTTON_DOWN_PIN = 3;
const uint8_t BUTTON_RESET_PIN = 4;

// --- Servo Pin ---
const uint8_t SERVO_PIN = 9;

// --- LCD Pins ---
const uint8_t RS = 12;
const uint8_t EN = 11;
const uint8_t D4 = 5;
const uint8_t D5 = 6;
const uint8_t D6 = 7;
const uint8_t D7 = 8;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
Servo myServo;

int currentAngle = 90;
const int stepSize = 5;
unsigned long lastPressTime = 0;

void updateDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Servo Position");
  lcd.setCursor(0, 1);
  lcd.print("Angle: ");
  if (currentAngle < 100) {
    lcd.print(" ");
  }
  lcd.print(currentAngle);
  lcd.print(char(223));
  lcd.print(" ");
}

bool buttonPressed(uint8_t pin) {
  return digitalRead(pin) == LOW;
}

void moveServoTo(int angle) {
  currentAngle = constrain(angle, 0, 180);
  myServo.write(currentAngle);
  updateDisplay();
}

void setup() {
  pinMode(BUTTON_UP_PIN, INPUT_PULLUP);
  pinMode(BUTTON_DOWN_PIN, INPUT_PULLUP);
  pinMode(BUTTON_RESET_PIN, INPUT_PULLUP);

  lcd.begin(16, 2);
  myServo.attach(SERVO_PIN);

  moveServoTo(currentAngle);
}

void loop() {
  unsigned long now = millis();

  // Debounce logic: allow button actions only every 150 ms
  if (now - lastPressTime >= 150) {
    if (buttonPressed(BUTTON_UP_PIN)) {
      moveServoTo(currentAngle + stepSize);
      lastPressTime = now;
    }
    else if (buttonPressed(BUTTON_DOWN_PIN)) {
      moveServoTo(currentAngle - stepSize);
      lastPressTime = now;
    }
    else if (buttonPressed(BUTTON_RESET_PIN)) {
      moveServoTo(90);
      lastPressTime = now;
    }
  }
}
