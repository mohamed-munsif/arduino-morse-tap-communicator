# Morse Code and Tap Code Arduino Project

An Arduino-based communication system that can encode and decode both Morse code and Tap code using an LCD display and input buttons.

## Features

- **Dual Mode Operation**: Switch between Morse code and Tap code modes
- **Morse Code Mode**: 
  - Input dots and dashes using buttons
  - Real-time translation to letters
  - Audio feedback with piezo buzzer
  - Support for letter spacing and word spacing
- **Tap Code Mode**: 
  - Navigate through a 5x5 grid using row/column buttons
  - Visual display of current position and selected letter
  - Audio feedback for navigation

## Hardware Requirements

- Arduino board (Uno, Nano, etc.)
- 16x2 LCD display
- 4 push buttons (row/column or dot/dash, enter, toggle switch)
- Piezo buzzer
- Breadboard and jumper wires
- Resistors for LCD contrast and button pull-ups (if needed)

## Pin Configuration

- **LCD**: Pins 7, 8, 9, 10, 11, 12
- **Toggle Switch**: Pin 2
- **Row Button / Dot Button**: Pin 3
- **Column Button / Dash Button**: Pin 4
- **Enter Button**: Pin 5
- **Piezo Buzzer**: Pin 13

## How to Use

### Morse Code Mode (Toggle Switch LOW)
1. Press the dot button (pin 3) to add a dot (.)
2. Press the dash button (pin 4) to add a dash (-)
3. Press enter once to translate the current morse sequence to a letter
4. Press enter twice quickly to add a space between words
5. Press enter three times quickly to clear the display

### Tap Code Mode (Toggle Switch HIGH)
1. Press the row button (pin 3) to cycle through rows (1-5)
2. Press the column button (pin 4) to cycle through columns (1-5)
3. The LCD displays the current row/column position and the corresponding letter

## Circuit Diagram

Connect the components according to the pin configuration above. Make sure to include appropriate pull-up resistors for the buttons and a contrast adjustment potentiometer for the LCD.

## Installation

1. Install the Arduino IDE
2. Open the `morse_and_tap.ino` file
3. Upload the code to your Arduino board
4. Connect the hardware according to the pin configuration

## Tap Code Reference

The Tap Code uses a 5x5 grid:

```
   1  2  3  4  5
1  A  B  C  D  E
2  F  G  H  I  J
3  K  L  M  N  O
4  P  Q  R  S  T
5  U  V  W  X  Y
```

Note: The letter 'Z' is not included in the standard Tap Code grid.

## License

This project is open source and available under the MIT License.
# arduino-morse-tap-communicator
