// LAB9-2-7 (Sketch 14-4, p.29)

int Enable1 = 38; // 모터 활성화 
int PWM1 = 9; // 모터 속도 제어 
int DIR1 = 39; // 모터 방향 제어 

void setup() {
  pinMode(Enable1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(DIR1, OUTPUT);
  digitalWrite(Enable1, HIGH); // 모터 제어 가능 상태
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(A0);
  int speed = map(reading, 0, 1023, -255, 255);

  if (speed > 0) {
    digitalWrite(DIR1, HIGH); // 정방향 회전 - HIGH 시계방향 회전 ! 
    int pwm_value = 255 - speed; // HIGH 상태일 경우, 255가 최저 속도 
    analogWrite(PWM1, pwm_value);
    Serial.print(String("Reading : ") + reading);
    Serial.println(String(", Clockwise : ") + speed);
  }
  else {
    digitalWrite(DIR1, LOW); // 역방향 회전 - LOW 반시계방향 회전 !
    int pwm_value = abs(speed); // LOW 상태일 경우, 255가 최고 속도 
    analogWrite(PWM1, pwm_value);
    Serial.print(String("Reading : ") + reading);
    Serial.println(String(", Anti-clockwise : ") + pwm_value);
  }
  
  delay(1000);
}
