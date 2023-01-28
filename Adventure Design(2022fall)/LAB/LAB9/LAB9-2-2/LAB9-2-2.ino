// LAB9-2-2 (Sketch 14-1, p.24)

int Enable1 = 38; // 모터 1
int PWM1 = 9;
int DIR1 = 39;

int Enable2 = 40; // 모터 2
int PWM2 = 10;
int DIR2 = 41;

void setup() {
  pinMode(Enable1, OUTPUT);
  digitalWrite(Enable1, LOW); // 모터 제어 불가능 상태
  pinMode(PWM1, OUTPUT);
  pinMode(DIR1, OUTPUT);
  pinMode(Enable2, OUTPUT);
  digitalWrite(Enable2, LOW); // 모터 제어 불가능 상태
  pinMode(PWM2, OUTPUT);
  pinMode(DIR2, OUTPUT);
}

void loop() {
  // 모터 1 제어
  digitalWrite(Enable1, HIGH); // 모터 제어 가능 상태
  digitalWrite(DIR1, HIGH); // 정방향 회전
  digitalWrite(PWM1, LOW); // 최고 속도
  delay(4000);
  digitalWrite(PWM1, HIGH); // 속도 0
  delay(200);
  digitalWrite(DIR1, LOW); // 역방향 회전
  digitalWrite(PWM1, HIGH); // 최고 속도
  delay(4000);
  digitalWrite(PWM1, LOW); // 속도 0
  delay(200);
  digitalWrite(Enable1, LOW); // 모터 제어 불가능 상태
}
