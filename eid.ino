#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

// হার্ট আইকন
byte heart[8] = {
  0b00000, 0b01010, 0b11111, 0b11111, 0b11111, 0b01110, 0b00100, 0b00000
};

// স্মাইলি ফেস আইকন
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
  // ১. ঈদ মোবারক এবং নিচে Everyone (স্মাইলি সহ)
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Eid Mubarak");
  lcd.setCursor(3, 1);
  lcd.write(1);         // বাম পাশে স্মাইলি
  lcd.print(" Everyone ");
  lcd.write(1);         // ডান পাশে স্মাইলি
  delay(2500);

  // ২. ব্র্যান্ডিং এবং ছোট টেক্সট (Welcome)
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("CodeWithPranta");
  
  // ছোট টেক্সট ব্লিংকিং
  for(int i=0; i<3; i++) {
    lcd.setCursor(4, 1);
    lcd.print("Welcome!"); 
    delay(500);
    lcd.setCursor(4, 1);
    lcd.print("        "); 
    delay(300);
  }
  delay(1000);

  // ৩. সাবস্ক্রাইব মেসেজ
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Please Subscribe");
  lcd.setCursor(0, 1);
  lcd.print("  My Channel ");   
  lcd.write(0);                 // শেষে হার্ট
  delay(4000); 
}