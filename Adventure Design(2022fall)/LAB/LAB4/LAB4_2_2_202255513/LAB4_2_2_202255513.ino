// LAB4_2_2_202255513

int button = 21;                       // 버튼 연결 핀

void setup() {
  Serial.begin(9600);                  // 시리얼 통신 초기화
  pinMode(button, INPUT_PULLUP);       // 버튼 연결 핀을 입력으로 설정
}

void loop() {
  Serial.println(digitalRead(button)); // 버튼 상태 출력
  delay(1000);
}
