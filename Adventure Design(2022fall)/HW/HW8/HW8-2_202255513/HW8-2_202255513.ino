// HW8-2_202255513

 /* Text LCD를 통해 온도센서, 조도센서 값 출력(1초 간격)
 */

#include <LiquidCrystal.h>

// 핀 번호 (RS, E, DB4, DB5, DB6, DB7)
LiquidCrystal lcd(44, 45, 46, 47, 48, 49); // LCD 연결

//섭씨 표현
byte user1[8] = {
  0B01000,
  0B00011, 
  0B00100, 
  0B01000, 
  0B10000,
  0B01000,
  0B00100,
  0B00011
};

unsigned long time_previous, time_current;

// 온도센서 값읽고 반환
float readTemperature() {
  int reading = analogRead(A1); 
  float voltage = reading * 5.0 / 1024.0;
  float temp_C = voltage * 100;
  return temp_C;
}

// 조도 센서 읽기
float readIlluminance() {
  int reading = analogRead(A2); 
  float voltage = reading * 5.0 / 1024.0;
  return voltage;
}


void setup() {
  lcd.createChar(0, user1);
  lcd.begin(16,2);
  lcd.clear();
  time_previous = millis();
}

void loop() {
   time_current = millis();
   float temp = readTemperature();
   float light = readIlluminance();
   if(time_current - time_previous >= 1000){
    time_previous=time_current;
    lcd.setCursor(0,0);
    lcd.print("Temp : ");
    lcd.print(temp);
    lcd.write(byte(0));
    
    lcd.setCursor(0,1);
    lcd.print("Light : ");
    lcd.print(light);
   }
}
