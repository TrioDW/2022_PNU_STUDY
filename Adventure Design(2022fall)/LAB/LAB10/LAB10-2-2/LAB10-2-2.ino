// LAB10-2-2 Master (Sketch 20-1, p.18)

#include <SPI.h>

int SS_arduino = 53;

void setup() {
  pinMode(SS_arduino, OUTPUT);
  digitalWrite(SS_arduino, HIGH); // 슬레이브가 선택되지 않은 상태

  SPI.begin();
  // 안정적인 전송을 위해 분주비를 높여 전송속도를 낮춤
  SPI.setClockDivider(SPI_CLOCK_DIV16);
}

void loop() {
  const char* p = "Hello, World\n";
  digitalWrite(SS_arduino, LOW); // 슬레이브 선택
  for (int i = 0; i < strlen(p); i++) // 문자열 전송
    SPI.transfer(p[i]);
  digitalWrite(SS_arduino, HIGH); // 슬레이브 선택 해제
  delay(1000);
}
