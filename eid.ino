#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 
byte heart[8] = {
  0b00000, 0b01010, 0b11111, 0b11111, 0b11111, 0b01110, 0b00100, 0b00000
};
byte smiley[8] = {
  0b00000, 0b01010, 0b00000, 0b00000, 0b10001, 0b01110, 0b00000, 0b00000
};

void setup() {
  lcd.init();
  lcd.backlight();
  
  lcd.createChar(0, heart);
  lcd.createChar(1, smiley);
}

void loop() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Eid Mubarak");
  lcd.setCursor(3, 1);
  lcd.write(1);         
  lcd.print(" Everyone ");
  lcd.write(1);         
  delay(2500);

  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("CodeWithPranta");
  
  for(int i=0; i<3; i++) {
    lcd.setCursor(4, 1);
    lcd.print("Welcome!"); 
    delay(500);
    lcd.setCursor(4, 1);
    lcd.print("        "); 
    delay(300);
  }
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Please Subscribe");
  lcd.setCursor(0, 1);
  lcd.print("  My Channel ");   
  lcd.write(0);                
  delay(4000); 
}