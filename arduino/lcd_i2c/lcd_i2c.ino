#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
byte a[8] = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111};

void setup()
{
	// initialize the LCD
	lcd.begin();

	// Turn on the blacklight and print a message.
	lcd.backlight();
	
}

void loop()
{
  lcd.setCursor(0, 0);
lcd.print("Hello World!");
lcd.setCursor(0, 1);
lcd.print(byte(a));// Do nothing here...
}
