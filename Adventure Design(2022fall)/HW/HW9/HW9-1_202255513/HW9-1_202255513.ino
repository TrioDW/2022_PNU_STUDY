// HW9-1_202255513

 /* 풀다운 저항 버튼 2개를 연결
 * 14번 핀에 연결된 버튼을 누르면 서보모터 위치 10도 증가
 * 15번 핀에 연결된 버튼을 누르면 서보모터 위치 10도 감소
 */

#include <Servo.h>

Servo myServo;
int servoPin = 11;
int buttons[] = {14, 15};
int angle = 0;
int angle_step = 10;

void setup() {
  myServo.attach(servoPin);
  myServo.write(angle); // 0도에서 시작 
  pinMode(buttons[0],INPUT);
  pinMode(buttons[1],INPUT);
}

void loop() {
  boolean plus_state = digitalRead(buttons[0]);
  boolean minus_state = digitalRead(buttons[1]);
  
  if(plus_state ==true && minus_state == false){
    if(angle >= 180){ // 180도를 넘어가면 0도로 지정
      angle = 0;
    }
    //10도씩 증가
    angle += angle_step;
    myServo.write(angle);
    delay(5);
  }
  else if(plus_state ==false && minus_state == true){
    if(angle <= 0){ // 0도를 넘어가면 180도로 지정
      angle = 180;
    }
    //10도씩 감소
    angle -= angle_step;
    myServo.write(angle);
    delay(5);
  }
  delay(100);
}
