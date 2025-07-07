# 📡 Morse Code and Tap Code Arduino Communicator

[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)](https://www.arduino.cc/)
[![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Tinkercad](https://img.shields.io/badge/Tinkercad-1477D1?style=for-the-badge&logo=autodesk&logoColor=white)](https://www.tinkercad.com/)

A versatile Arduino-based dual-mode communication system that supports both **Morse code** and **Tap code** encoding/decoding. Perfect for educational purposes, emergency communication scenarios, or learning historical communication methods.

## 🎯 Features

## 🎯 Features

- 🔄 **Dual Mode Operation**: Seamlessly switch between Morse code and Tap code modes
- 📻 **Morse Code Mode**: 
  - ⚫ Input dots and dashes using dedicated buttons
  - 🔤 Real-time translation to letters with instant feedback
  - 🔊 Audio feedback with piezo buzzer for authentic experience
  - 📝 Support for letter spacing and word spacing
  - 🧹 Triple-press enter to clear display
- 📐 **Tap Code Mode**: 
  - 🎯 Navigate through a 5×5 grid using row/column buttons
  - 📺 Visual display of current position and selected letter
  - 🎵 Audio feedback for navigation confirmation
- 💾 **User-Friendly Interface**: Clear LCD display with intuitive controls

## 🛠️ Hardware Requirements

## 🛠️ Hardware Requirements

| Component | Quantity | Purpose |
|-----------|----------|---------|
| Arduino Board (Uno/Nano) | 1 | Main microcontroller |
| 16×2 LCD Display | 1 | Visual output and feedback |
| Push Buttons | 4 | Input controls |
| Toggle Switch | 1 | Mode selection |
| Piezo Buzzer | 1 | Audio feedback |
| Breadboard | 1 | Circuit prototyping |
| Jumper Wires | Multiple | Connections |
| 10kΩ Resistors | 4-5 | Button pull-ups & LCD contrast |
| 220Ω Resistor | 1 | Piezo buzzer current limiting |

## 🔌 Pin Configuration

## 🔌 Pin Configuration

| Component | Arduino Pin | Notes |
|-----------|-------------|-------|
| **LCD Display** | 7, 8, 9, 10, 11, 12 | Standard LiquidCrystal library pins |
| **Toggle Switch** | 2 | Mode selector (HIGH = Tap, LOW = Morse) |
| **Row/Dot Button** | 3 | Row navigation (Tap) / Dot input (Morse) |
| **Column/Dash Button** | 4 | Column navigation (Tap) / Dash input (Morse) |
| **Enter Button** | 5 | Confirm selection / Letter spacing |
| **Piezo Buzzer** | 13 | Audio feedback |

## 🎮 How to Use

## 🎮 How to Use

### 📻 Morse Code Mode (Toggle Switch LOW)

```
🔘 Dot Button (Pin 3)    → Add dot (.) to sequence
🔲 Dash Button (Pin 4)   → Add dash (-) to sequence
🔵 Enter × 1            → Translate current sequence to letter
🔵 Enter × 2 (quick)    → Add space between words
🔵 Enter × 3 (quick)    → Clear entire display
```

**Example Sequence:**
- Input: `.- -... -.-.` 
- Output: `ABC`

### 📐 Tap Code Mode (Toggle Switch HIGH)

```
🔺 Row Button (Pin 3)    → Cycle through rows (1-5)
🔻 Column Button (Pin 4) → Cycle through columns (1-5)
📺 LCD Display         → Shows current position & letter
```

**Example:**
- Row 2, Column 3 = Letter `H`

## 🔧 Installation & Setup

## 🔧 Installation & Setup

### Software Setup
1. 📥 **Install Arduino IDE** from [arduino.cc](https://www.arduino.cc/en/software)
2. 📂 **Download** or clone this repository
3. 📋 **Open** `morse_and_tap.ino` in Arduino IDE
4. 🔗 **Connect** your Arduino board via USB
5. ⚡ **Upload** the code to your Arduino

### Hardware Assembly
1. 🔌 **Connect LCD** to pins 7-12 as per pin configuration
2. 🔘 **Wire buttons** to pins 2-5 with pull-up resistors
3. 🔊 **Connect piezo buzzer** to pin 13
4. 🔋 **Power** the Arduino via USB or external supply

## 🌐 Online Simulation

Try the project without physical hardware! Access the **Tinkercad simulation**:

[![Tinkercad Simulation](https://img.shields.io/badge/🔗_Try_Online_Simulation-Tinkercad-1477D1?style=for-the-badge)](https://www.tinkercad.com/things/8HkiRkxXjXT-morse-and-tap-v1?sharecode=vsdd2gJJ9Uky0NXtI056EeGX9bPACdNzHFJiHvPIP_Q)

**Features in simulation:**
- ✅ Full circuit diagram
- ✅ Interactive components
- ✅ Real-time code execution
- ✅ No hardware required

## 📋 Reference Tables

## 📋 Reference Tables

### 📐 Tap Code Grid (5×5)

The Tap Code uses a 5×5 grid where each letter is represented by row and column positions:

```
      COL 1   COL 2   COL 3   COL 4   COL 5
ROW 1   A       B       C       D       E
ROW 2   F       G       H       I       J
ROW 3   K       L       M       N       O
ROW 4   P       Q       R       S       T
ROW 5   U       V       W       X       Y
```

> 📝 **Note:** The letter 'Z' is not included in the standard Tap Code grid. In practice, 'C' or 'S' is often used as a substitute.

### 📻 Morse Code Reference

<details>
<summary>Click to expand Morse Code alphabet</summary>

| Letter | Morse Code | Letter | Morse Code |
|--------|------------|--------|------------|
| A      | .-         | N      | -.         |
| B      | -...       | O      | ---        |
| C      | -.-.       | P      | .--.       |
| D      | -..        | Q      | --.-       |
| E      | .          | R      | .-.        |
| F      | ..-.       | S      | ...        |
| G      | --.        | T      | -          |
| H      | ....       | U      | ..-        |
| I      | ..         | V      | ...-       |
| J      | .---       | W      | .--        |
| K      | -.-        | X      | -..-       |
| L      | .-..       | Y      | -.--       |
| M      | --         | Z      | --..       |

</details>

## 🎵 Audio Feedback System

The piezo buzzer provides different tones for various actions:

| Action | Frequency | Duration | Purpose |
|--------|-----------|----------|---------|
| Dot Input | 1000 Hz | 200ms | Morse dot confirmation |
| Dash Input | 1500 Hz | 200ms | Morse dash confirmation |
| Row Navigation | 1000 Hz | 200ms | Tap code row change |
| Column Navigation | 1500 Hz | 200ms | Tap code column change |
| Enter Actions | 2000 Hz | 200ms | Confirmation/Clear actions |

## 🚨 Troubleshooting

### Common Issues & Solutions

| Problem | Possible Cause | Solution |
|---------|----------------|----------|
| LCD shows nothing | Contrast issue | Adjust contrast potentiometer |
| Buttons not responding | Wiring/Pull-up resistors | Check connections & add 10kΩ pull-ups |
| No audio feedback | Piezo connection | Verify pin 13 connection |
| Incorrect characters | Timing issues | Ensure proper debounce delays |
| Mode not switching | Toggle switch wiring | Check pin 2 connection |

## 🎓 Educational Applications

This project is perfect for:

- 📚 **STEM Education**: Learning about digital communication
- 🏛️ **History Lessons**: Understanding wartime communication methods
- 🔬 **Arduino Projects**: Hands-on microcontroller programming
- 🧩 **Problem Solving**: Encoding/decoding logic implementation
- 👨‍👩‍👧‍👦 **Family Activities**: Fun coding games for all ages

## 🤝 Contributing

Contributions are welcome! Here are ways to contribute:

1. 🐛 **Report bugs** via GitHub issues
2. 💡 **Suggest features** or improvements
3. 🔧 **Submit pull requests** with enhancements
4. 📖 **Improve documentation**
5. 🎨 **Add circuit diagrams** or schematics

## 📄 License

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

## 🌟 Acknowledgments

- 📡 Inspired by historical military communication systems
- 🎵 Arduino community for excellent libraries and support
- 🔧 Tinkercad for providing an excellent simulation platform

---

<div align="center">

**⭐ Star this repository if you found it helpful!**

Made with ❤️ by [Munsif](https://github.com/Munsif)

</div>
