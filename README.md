# Arduino Proteus Servo Motor Position Control System

Design and Simulation of an Arduino Proteus-Based Servo Motor Position Control System Using Push Buttons and LCD Feedback.

## Overview
This project demonstrates a simple closed-loop-style position control system for a standard hobby servo motor using an Arduino Uno and a 16x2 LCD. The user can move the servo shaft to a precise angle using push buttons, and the selected position is shown on the LCD in real time.

The system is suitable for educational demonstrations, embedded control labs, and Proteus-based simulation workflows.

## Features
- Angular control of a servo motor from 0° to 180°
- Push-button position adjustment
- Real-time LCD feedback showing the current angle
- Reset to the center position (90°)
- Easy to simulate in Proteus using standard components

## System Components
- Arduino Uno
- SG90 or similar hobby servo motor
- 16x2 LCD display
- 3 push buttons
- 10 kΩ potentiometer (optional, for LCD contrast)
- Power supply (5V)
- Breadboard and jumper wires

## Working Principle
The Arduino reads button inputs and modifies the servo position in fixed steps. Each press of the control button updates the angle, and the servo rotates to the new angle. The LCD continuously displays the current position.

## Hardware Connection

```text
Arduino Uno                Components
---------                 ----------
D2  --------------------- UP button (to GND via button)
D3  --------------------- DOWN button (to GND via button)
D4  --------------------- RESET button (to GND via button)
D9  --------------------- Servo signal pin
5V ---------------------- Servo VCC and LCD VDD
GND --------------------- Servo GND and LCD GND

LCD Connections
RS -> D12
EN -> D11
D4 -> D5
D5 -> D6
D6 -> D7
D7 -> D8
VO -> 10k potentiometer (or fixed contrast setup)
```

## Example LCD Output
```text
Servo Position
Angle: 90°
a
```

## Proteus Simulation Setup
1. Open Proteus and place:
   - Arduino UNO
   - Servo Motor
   - 16x2 LCD
   - Push buttons
   - Ground and 5V rails
2. Connect the pins according to the wiring table above.
3. Load the Arduino sketch into the Arduino UNO.
4. Run the simulation.
5. Press the buttons to observe the servo movement and the updated LCD value.

## Arduino Sketch
The project code is located at:
- `servo_position_control.ino`

## Project Structure
```text
servo-motor/
├── README.md
├── servo_position_control.ino
└── .gitignore
```

## Notes
- The code uses the Arduino `Servo` library and the `LiquidCrystal` library.
- The buttons are configured with internal pull-up resistors (`INPUT_PULLUP`), so each button connects to ground when pressed.
- The default centre position is 90°, which is suitable for a standard 0°–180° servo.

## License
This project is provided for educational purposes and can be freely adapted for learning and experimentation.

## Future Improvements
- Add limit switches for safety
- Add EEPROM to retain the last position after power loss
- Add an optional potentiometer as a manual input mode
- Extend to multiple servo axes or a motorized positioning system
