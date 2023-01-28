// LAB6-2-3 (Sketch 8-1, p.20)

int pin_button = 14;  // 버튼 연결 핀 
int pin_LED1 = 13, pin_LED2 = 2;  // LED 연결 핀 
boolean LED_state1 = false;  // LED 상태
boolean LED_state2 = false;

void setup() {
  pinMode(pin_button, INPUT);
  pinMode(pin_LED1, OUTPUT);
  digitalWrite(pin_LED1, LED_state1);
  pinMode(pin_LED2, OUTPUT);
  digitalWrite(pin_LED2, LED_state2);  
}

void loop() {
  digitalWrite(pin_LED1, LED_state1);
  delay(1000);  // 1초 대기
  LED_state1 = !LED_state1;  // 13번 LED 반전 

  if (digitalRead(pin_button)) {  // 버튼이 눌러진 경우 
    LED_state2 = !LED_state2;  // 2번 LED 반전
    digitalWrite(pin_LED2, LED_state2);
  }
}
