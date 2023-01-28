// LAB9-1-5 (Sketch 13-3, p.12)

#include <Servo.h>

Servo myServo; // 서보모터 변수 설정 
int servoPin = 11;
unsigned long time_previous, time_current;
int interval = 10; // 현재 이동 시간 간격
int angle = 0; // 현재 모터의 각도
int angle_step = 1; // 모터 각도의 증감(1 or -1)

void setup() {
  myServo.attach(servoPin); // 서보 모터 연결 
  Serial.begin(9600);
  myServo.write(angle); // 0°에서 시작
  delay(100);
  time_previous = millis();
}

void loop() {
  time_current = millis();

  if (time_current - time_previous >= interval) {
    time_previous = time_current;
    angle += angle_step; // 현재 각도 조정
    if (angle > 180) { // 180°를 넘어가면 방향 전환
      angle = 180;
      angle_step *= -1;
    }
    else if (angle < 0) { // 0°를 넘어가면 방향 전환
      angle = 0;
      angle_step *= -1;
    }
    myServo.write(angle);
  }
  int reading = analogRead(A0); // 가변저항 값 읽기
  int new_interval = map(reading, 0, 1023, 5, 20);
  if (new_interval != interval) {
    interval = new_interval; // 이동 시간 간격 조정 
    Serial.print("Current Interval : ");
    Serial.println(interval);
  }
}
