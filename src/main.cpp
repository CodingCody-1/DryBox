#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 3
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27,20,4);

int fan = 0;

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();

  lcd.init();
  lcd.backlight();
}

void loop() {
  float h = dht.readHumidity();
  delay(500);

  if (h >= 15 ){  //humidity greater than 15
   digitalWrite(5, HIGH);
   fan = 1;
  }
  else if (h <= 10){  //humidity less than 10
   digitalWrite(5, LOW);
   fan = 0;
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(h);
  lcd.print("%");

  lcd.setCursor(0,1);
  if (fan = 1){
    lcd.print("Fan: ON");
  }
  else {
    lcd.print("Fan: OFF");
  }
}