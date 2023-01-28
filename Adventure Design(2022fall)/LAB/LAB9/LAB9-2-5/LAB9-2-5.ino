// LAB9-2-5 (Sketch 14-3, p.27)

int Enable1 = 38;
int PWM1 = 9;
int DIR1 = 39;
int button_pin = 14;
boolean direction = true;

void setup() {
  pinMode(Enable1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(DIR1, OUTPUT);
  digitalWrite(Enable1, HIGH); // 모터 제어 가능 상태
  digitalWrite(DIR1, direction); // 초기 방향은 정방향
  digitalWrite(PWM1, !direction); // 최고 속도
  pinMode(button_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(button_pin)) {
    direction = !direction;
    if (direction) // clockwise
      Serial.println("Clockwise...");
    else
      Serial.println("Anti-clockwise...");
    digitalWrite(DIR1, direction);
    digitalWrite(PWM1, !direction);
    delay(2000);
  }
}
