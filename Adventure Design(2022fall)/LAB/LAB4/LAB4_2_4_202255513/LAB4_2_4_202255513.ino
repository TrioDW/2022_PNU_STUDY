// LAB4_2_4_202255513

int pins_LED[] = {2, 3}; // LED 연결 핀
// 버튼 연결 핀 (15 : 풀다운 저항, 16 : 풀업 저항)
int pins_button[] = {15, 16};

boolean on_off_pattern[2][2] = { // 점멸 패턴
  {false, true}, // 풀다운 저항을 사용한 경우
  {true, false} // 풀업 저항을 사용한 경우
};

void setup() {
  Serial.begin(9600); // 시리얼 통신 초기화
  for (int i = 0; i < 2; i++) {
    pinMode(pins_button[i], INPUT); // 버튼 연결 핀을 입력으로 설정
    pinMode(pins_LED[i], OUTPUT); // LED 연결 핀을 출력으로 설정
  }
}

void loop() {
  for (int i = 0; i < 2; i++) {
    boolean state = digitalRead(pins_button[i]); // 버튼 상태 읽기
    digitalWrite(pins_LED[i], on_off_pattern[i][state]); // LED 출력
    Serial.print(on_off_pattern[i][state]);
    Serial.print(" ");
  }
  Serial.println();
  delay(1000);
}
