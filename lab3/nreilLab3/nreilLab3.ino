/*
Nolan Reilly, 678442166, nreil
Lab 3 - Liquid Crystal Display - LCD
Description: The code below uses the imported libary LiquidCrystal to manipulate
a 16x2 LCD panel to display scrolling text and a centered name that doesn't move
Assumptions: Assume that the Arduino, and all other connected tech works as intended.
References:
- https://www.youtube.com/watch?v=0TIbVA_J_vM&ab_channel=AutomationBD
- https://www.youtube.com/watch?v=_6_F6B0rd6M&t=623s&ab_channel=BV3D%3ABryanVines
*/

#include <LiquidCrystal.h>

void updateLCDDisplay();

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

char* text = " Please fill out the Captcha ";  // Text that will be used for scrolling
int lineNum = 0; // Row to display text
int iCursor = 0;

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(1, 1); // Set the cursor to column 1, and row 1
  lcd.print("    Nolan  ");
}

void loop() {
  updateLCDDisplay(); // Function used for the scroling text
  delay(500);
}

void updateLCDDisplay() {
  int lenOfText = strlen("Please fill out the Captcha") + 3;

  // Reset variable
  if (iCursor ==(lenOfText - 1)) {
    iCursor = 0;
  } 

  lcd.setCursor(0, lineNum);

  // This executes the 16 showable character 
  if (iCursor < lenOfText - 16) {
    for (int i = iCursor; i < iCursor + 16; i++) {
      lcd.print(text[i]);  // Print the message to the LCD
    }
  } else {
    for (int i = iCursor; i < (lenOfText - 1); i++) {
      lcd.print(text[i]);  // print the message to the LCD
    }
    for (int i = 0; i <= 16 - (lenOfText - iCursor); i++) {
      lcd.print(text[i]); // print the message to the LCD
    }
  }

  iCursor++;
}
