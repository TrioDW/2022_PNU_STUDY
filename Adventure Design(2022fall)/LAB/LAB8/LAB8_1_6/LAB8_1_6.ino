// 0에서 9까지 숫자 표현을 위한
// 세그먼트 a, b, c, d, e, f, g, dp의 패턴
byte patterns[] = {
    0xFC, // 0b11111100, '0'
  0x60, // 0b01100000, '1'
  0xDA, // 0b11011010, '2'
  0xF2, // 0b11110010, '3'
  0x66, // 0b01100110, '4'
  0xB6, // 0b10110110, '5'
  0xBE, // 0b10111110, '6'
  0xE4, // 0b11100100, '7'
  0xFE, // 0b11111110, '8'
  0xE6  // 0b11100110, '9'
};


int digit_select_pin[] = {66, 67, 68, 69}; // 자릿수 선택 핀

// 7세그먼트 모듈 연결 핀 ‘a, b, c, d, e, f, g, dp’ 순서
int segment_pin[] = {58, 59, 60, 61, 62, 63, 64, 65};

int SEGMENT_DELAY = 5; // 숫자 표시 사이의 시간 간격

void setup() {
  for (int i = 0; i < 4; i++) { // 자릿수 선택 핀을 출력으로 설정
    pinMode(digit_select_pin[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) { // 세그먼트 제어 핀을 출력으로 설정
    pinMode(segment_pin[i], OUTPUT);
  }
}

// 해당 자리에 숫자 하나를 표시하는 함수
void show_digit(int pos, int number) { // (위치, 출력할 숫자)
  for (int i = 0; i < 4; i++) {
    if (i + 1 == pos) // 해당 자릿수의 선택 핀만 LOW로 설정
      digitalWrite(digit_select_pin[i], LOW);
    else // 나머지 자리는 HIGH로 설정
      digitalWrite(digit_select_pin[i], HIGH);
  }
  for (int i = 0; i < 8; i++) {
    boolean on_off = bitRead(patterns[number], 7 - i);
    digitalWrite(segment_pin[i], on_off);
  }
}

// 4자리 7세그먼트 표시 장치에 4자리 숫자를 표시하는 함수
void show_4_digit(int _number) {
  int number = _number;
  number = number % 10000; // 4자리로 제한
  int thousands = number / 1000; // 천 자리
  number = number % 1000;
  int hundreads = number / 100; // 백 자리
  number = number % 100;
  int tens = number / 10; // 십 자리
  int ones = number % 10; // 일 자리
  if (_number > 999) show_digit(1, thousands);
  delay(SEGMENT_DELAY);
  if (_number > 99) show_digit(2, hundreads);
  delay(SEGMENT_DELAY);
  if (_number > 9) show_digit(3, tens);
  delay(SEGMENT_DELAY);
  show_digit(4, ones);
  delay(SEGMENT_DELAY);
}

void loop() {
  int reading = analogRead(A0); // 가변저항 값 읽기
  show_4_digit(reading); // 가변저항 값 표시
}
