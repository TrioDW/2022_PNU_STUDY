// LAB4_2_5_202255513

int pin_button = 15; // 버튼 연결 핀
boolean state_previous = false; // 버튼의 이전 상태
boolean state_current; // 버튼의 현재 상태
int count = 0; // 버튼을 누른 횟수

void setup() {
  Serial.begin(9600); // 시리얼 통신 초기화
  pinMode(pin_button, INPUT); // 버튼 연결 핀을 입력으로 설정
}

void loop() {
  state_current = digitalRead(pin_button); // 버튼 상태 읽기
  if (state_current) { // 버튼을 누른 경우
    if (state_previous == false) { // 이전 상태와 비교
      count++; // 상태가 바뀐 경우에만 횟수 증가
      state_previous = true;
      Serial.println(count);
    }
    // delay(50); // 디바운싱
  }
  else {
    state_previous = false;
  }
}
