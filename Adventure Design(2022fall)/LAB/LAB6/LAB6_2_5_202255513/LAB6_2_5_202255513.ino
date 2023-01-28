// LAB6-2-5 (Sketch 8-6, p.26)

int pin_LED = 13;  // LED 연결 핀 
unsigned long time_previous, time_current;
unsigned long interval = 1000;  // 점멸 간격
boolean LED_state = false;  // LED 상태 

void setup() {
  pinMode(A0, INPUT);
  pinMode(pin_LED, OUTPUT);
  digitalWrite(pin_LED, LED_state);
  Serial.begin(9600);
  time_previous = millis();  // 현재 시간 
}

void loop() {
  time_current = millis();
  if (time_current - time_previous >= interval) {
    Serial.print("Current interval is ");
    Serial.print(interval);
    Serial.println(" ms.");
    time_previous = time_current;  // 시작 시간 갱신 
    LED_state = !LED_state;  // LED 반전
    digitalWrite(pin_LED, LED_state);
  }

  int adc = analogRead(A0);  // 가변저항 읽기
  interval = map(adc, 0, 1023, 500, 1500);  // 점멸 간격으로 변환
  // 0.5 ~ 1.5초 사이의 시간으로 맵핑 
}
