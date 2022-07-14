#include "dht.h" 
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int pinoDHT11 = A2;
dht DHT;

void setup()
{
  Serial.begin(9600); 
  delay(2000); 

  lcd.begin(16, 2);
  pinMode(6,OUTPUT);
  analogWrite(6,5);
}


void loop()
{
  DHT.read11(pinoDHT11); 
  Serial.print("Umidade: "); 
  Serial.print(DHT.humidity); 
  Serial.print("%");
  Serial.print(" / Temperatura: ");
  Serial.print(DHT.temperature, 0); 
  Serial.println("*C");
  lcd.setCursor(0,0);
  lcd.print(DHT.humidity);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print(DHT.temperature, 0);
  lcd.print("*C");
  delay(2000); //NAO DIMINUIR ESSE VALOR
}
