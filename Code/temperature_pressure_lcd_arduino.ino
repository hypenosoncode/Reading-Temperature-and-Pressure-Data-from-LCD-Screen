#include <Wire.h>
#include <LiquidCrystal.h>
#include <Adafruit_BMP085.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Adafruit_BMP085 bmp180;
 
void setup() 
{
  Serial.begin(9600);
  Serial.println("BMP180 Algilandi!"); 
  
  if (!bmp180.begin()) 
  {
    Serial.println("BMP180 Bulunamadi");
    while (1) {}
  }
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Sicaklik: ");
  lcd.setCursor(0,1);
  lcd.print("Basinc: ");
}
 
void loop() 
{
  lcd.setCursor(0,0);
  lcd.print("Sicaklik:"); 
  lcd.print(bmp180.readTemperature());
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Basinc:");
  lcd.print(bmp180.readPressure());
  lcd.print(" Pa");
  delay(1000);
}
