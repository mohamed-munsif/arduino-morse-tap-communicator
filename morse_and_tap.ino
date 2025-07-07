#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int rowButton;
int colButton;
int dotButton;
int dashButton;
int enterButton;
int piezoPin = 13;
int toggleSwitch;
int row = 0;
int col = 0;
int tick = 10; // ms
char tapCode[5][5] = {
  {'A', 'B', 'C', 'D', 'E'},
  {'F', 'G', 'H', 'I', 'J'},
  {'K', 'L', 'M', 'N', 'O'},
  {'P', 'Q', 'R', 'S', 'T'},
  {'U', 'V', 'W', 'X', 'Y'}
};
String dictionary[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
                      "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
                      "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                      "-.--", "--.."};
char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
String morse = "";
String translation = "";
unsigned long lastEnterPressTime = 0;
int enterPressCount = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(2, INPUT); // toggle switch
  pinMode(3, INPUT); // row button / dot button
  pinMode(4, INPUT); // column button / dash button
  pinMode(5, INPUT); // enter button
  pinMode(piezoPin, OUTPUT); // piezo buzzer
}

void loop() {
  toggleSwitch = digitalRead(2);
  if (toggleSwitch == HIGH) {
    // Tap Code Mode
    rowButton = digitalRead(3);
    colButton = digitalRead(4);

    if (rowButton == HIGH) {
      row = (row + 1) % 5;
      tone(piezoPin, 1000, 200); // Play tone at 1000 Hz for 200 ms
      delay(200); // Debounce delay
    } else if (colButton == HIGH) {
      col = (col + 1) % 5;
      tone(piezoPin, 1500, 200); // Play tone at 1500 Hz for 200 ms
      delay(200); // Debounce delay
    }

    lcd.setCursor(0, 0);
    lcd.print("Row: ");
    lcd.print(row + 1);
    lcd.setCursor(0, 1);
    lcd.print("Col: ");
    lcd.print(col + 1);
    lcd.setCursor(8, 1);
    lcd.print(tapCode[row][col]);
  } else {
    // Morse Code Mode
    dotButton = digitalRead(3);
    dashButton = digitalRead(4);
    enterButton = digitalRead(5);

    if (dotButton == HIGH) {
      morse += ".";
      tone(piezoPin, 1000, 200); // Play tone at 1000 Hz for 200 ms
      delay(200); // Debounce delay
    } else if (dashButton == HIGH) {
      morse += "-";
      tone(piezoPin, 1500, 200); // Play tone at 1500 Hz for 200 ms
      delay(200); // Debounce delay
    } else if (enterButton == HIGH) {
      unsigned long currentTime = millis();
      if (currentTime - lastEnterPressTime < 500) { // 500 ms threshold for double/triple press
        enterPressCount++;
      } else {
        enterPressCount = 1;
      }
      lastEnterPressTime = currentTime;

      if (enterPressCount == 1) {
        translation += findInDictionary(morse);
        morse = "";
        tone(piezoPin, 2000, 200); // Play tone at 2000 Hz for 200 ms
        delay(200); // Debounce delay
        clearLine(1); // Clear the second line of the LCD
      } else if (enterPressCount == 2) {
        translation += " ";
        tone(piezoPin, 2000, 200); // Play tone at 2000 Hz for 200 ms
        delay(200); // Debounce delay
      } else if (enterPressCount == 3) {
        translation = "";
        morse = "";
        clearLine(0); // Clear the first line of the LCD
        clearLine(1); // Clear the second line of the LCD
        tone(piezoPin, 2000, 200); // Play tone at 2000 Hz for 200 ms
        delay(200); // Debounce delay
      }
    }

    // Check if the translation string exceeds the LCD width
    if (translation.length() > 16) {
      translation = translation.substring(translation.length() - 16); // Keep only the last 16 characters
    }

    writeLine(0, translation);
    writeLine(1, morse);
  }

  delay(tick);
}

char findInDictionary(String word) {
  for (int i = 0; i < 26; i++) {
    if (dictionary[i] == word) return alphabet[i];
  }
  return '?';
}

void writeLine(int line, String text) {
  lcd.setCursor(0, line);
  lcd.print(text);
}

void clearLine(int line) {
  lcd.setCursor(0, line);
  lcd.print("                "); // Print 16 spaces to clear the line
}