// HW10_board1_202255513
 /* 온도측정 및 송신
 * MEGA 2560의 UART Serial 통신을 사용
 * 하나의 보드에서 온도센서를 통해 온도를 측정해 1초 간격으로 다른 보드에 온도값 전송
 */

#include <SoftwareSerial.h>
// SoftwareSerial(RX, TX) 형식으로 메가2560의 핀과 교차하여 연결한다.
SoftwareSerial mySerial(4,5);

//온도 감지및 송신 보드
void setup() {
  mySerial.begin(9600); // 메가2560과의 시리얼 연결
  Serial.begin(9600); // 컴퓨터와의 시리얼 연결
}

float readTemperature() {
  // 온도 센서 읽기
  int reading = analogRead(A0);
  
  // ADC 반환값을 전압으로 변환
  float voltage = (reading * 5.0) / 1024.0;
  Serial.print (voltage);
  Serial.print (" V : ");
  
  // 전압에 100을 곱하면 섭씨 온도를 얻을 수 있다.
  float temp_C = voltage * 100;
  Serial.print(temp_C);
  Serial.print(" C\n");
  return temp_C;
}

void loop() {
  float retValue = readTemperature();
  String str = "Current temperature : "+String(retValue)+"\n";
  mySerial.print(str); //
  delay(1000);
}
