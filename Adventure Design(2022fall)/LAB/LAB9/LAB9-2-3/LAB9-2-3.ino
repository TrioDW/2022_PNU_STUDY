// LAB9-2-3 (Sketch 14-2, p.25)

int Enable1 = 38;
int PWM1 = 9;
int DIR1 = 39;

void setup() {
  pinMode(Enable1, OUTPUT);
  digitalWrite(Enable1, LOW); // 모터 제어 불가능 상태
  pinMode(PWM1, OUTPUT);
  pinMode(DIR1, OUTPUT);
}

void loop() {
  digitalWrite(Enable1, HIGH); // 모터 제어 가능 상태
  digitalWrite(DIR1, HIGH); // 정방향 회전
  for (int i = 255; i >= 0; i--) { // 모터 회전 속도 서서히 증가
    analogWrite(PWM1, i);
    delay(30);
  }
  digitalWrite(PWM1, HIGH); // 모터 정지
  
  delay(200);
  
  digitalWrite(DIR1, LOW); // 역방향 회전
  for (int i = 0; i < 256; i++) { // 모터 회전 속도 서서히 증가
    analogWrite(PWM1, i);
    delay(30);
  }
  digitalWrite(PWM1, LOW); // 모터 정지
  
  delay(200);
  
  digitalWrite(Enable1, LOW); // 모터 제어 불가능 상태
}
