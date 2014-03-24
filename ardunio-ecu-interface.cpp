/*********************

Example code for the Adafruit RGB Character LCD Shield and Library

This code displays text on the shield, and also reads the buttons on the keypad.
When a button is pressed, the backlight changes color.
 
**********************/

// include the library code:
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>

// The shield uses the I2C SCL and SDA pins. On classic Arduinos
// this is Analog 4 and 5 so you can't use those for analogRead() anymore
// However, you can connect other I2C sensors to the I2C bus and share
// the I2C bus.
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// These #defines make it easy to set the backlight color
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

long randNumber;

void setup() {
  // Debugging output
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);

  // Print a message to the LCD. We track how long it takes since
  // this library has been optimized a bit and we're proud of it :)
  lcd.print("Evolution IX");
  lcd.setBacklight(WHITE);
}

uint8_t i=0;
void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):

  uint8_t buttons = lcd.readButtons();
  if (buttons) {
    lcd.clear();
    lcd.setCursor(0,0);
    if (buttons & BUTTON_UP) {
      lcd.print("ENGINE TEMP ");
      lcd.setBacklight(RED);
    }
    if (buttons & BUTTON_DOWN) {
      lcd.print("MPG ");
      lcd.setBacklight(YELLOW);
    }
    if (buttons & BUTTON_LEFT) {
      lcd.print("OIL PRESSURE ");
      lcd.setBacklight(GREEN);
    }
    if (buttons & BUTTON_RIGHT) {
      lcd.print("OIL TEMP ");
      lcd.setBacklight(TEAL);
    }
    if (buttons & BUTTON_SELECT) {
      lcd.print("BOOST GAUGE ");
      lcd.setBacklight(VIOLET);
    }
  }
   if (buttons) {
    lcd.setCursor(0,1);  
    if (buttons & BUTTON_UP) {
        randNumber = random(400);
        if (randNumber <= 220) {
          lcd.print(randNumber);
          lcd.print(" degrees ");
        }
        if (randNumber > 220) {
         lcd.print("Too Hot!"); 
        }
      lcd.setBacklight(RED);
    }
    if (buttons & BUTTON_DOWN) {
       randNumber = random(40);
          lcd.print(randNumber);
          lcd.print(" miles per gal ");
          lcd.setBacklight(YELLOW);
    }
    if (buttons & BUTTON_LEFT) {
      randNumber = random(400);
        if (randNumber <= 600) {
          lcd.print(randNumber);
          lcd.print(" psi ");
      }
      if (randNumber > 600) {
        lcd.print("Danger! Too High! ");
      }
      lcd.setBacklight(GREEN);
    }
    if (buttons & BUTTON_RIGHT) {
      randNumber = random(400);
        if (randNumber <= 320 && randNumber >= 32) {
          lcd.print(randNumber);
          lcd.print(" degrees ");
      }
        if (randNumber > 320) {
          lcd.print("Oil is too Hot! ");
        }
        if (randNumber < 32) {
          lcd.print("Oil is too cold ");
        }
      lcd.setBacklight(TEAL);
    }
    if (buttons & BUTTON_SELECT) {
       randNumber = random(45);
        if (randNumber > 14) {
          lcd.print("Boostaholic ");
        }
        if (randNumber <= 14) {
          lcd.print("Got Boost? ");
        }
      lcd.setBacklight(VIOLET);
    }
  }
}  
