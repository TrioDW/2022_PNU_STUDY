// HW6_202255513

int pin_LED1 = 2, pin_LED2 = 3; // LED 연결 핀
unsigned long time_previous1, time_previous2, time_current1, time_current2;
unsigned long interval1 = 1000;
unsigned long interval2 = 1000; // 점멸 간격
boolean LED_state1 = false;
boolean LED_state2 = false; // LED 상태

void setup() {
  pinMode(A0, INPUT);
  pinMode(pin_LED1, OUTPUT);
  pinMode(pin_LED2, OUTPUT);
  digitalWrite(pin_LED1, LED_state1);
  digitalWrite(pin_LED2, LED_state2);
  Serial.begin(9600);
  time_previous1 = millis();
  time_previous2 = millis(); // 현재 시간
}

void loop() {
  time_current1 = millis();
  time_current2 = millis();
  if (time_current1 - time_previous1 >= interval1) {
    Serial.print("Current interval1 is ");
    Serial.print(interval1);
    Serial.println(" ms.");
    time_previous1 = time_current1; // 시작 시간 갱신
    LED_state1 = !LED_state1; // LED 반전
    digitalWrite(pin_LED1, LED_state1);
  }
  if (time_current2 - time_previous2 >= interval2) {
    Serial.print("Current interval2 is ");
    Serial.print(interval2);
    Serial.println(" ms.");
    time_previous2 = time_current2; // 시작 시간 갱신
    LED_state2 = !LED_state2; // LED 반전
    digitalWrite(pin_LED2, LED_state2);
  }
  int adc = analogRead(A0); // 가변저항 읽기
  interval1 = map(adc, 0, 1023, 500, 1500);
  interval2 = map(adc, 0, 1023, 1500, 500); // 점멸 간격으로 변환
}
