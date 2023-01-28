// HW8-1_202255513

 /* 상향카운터(0~999), 하향카운터(999~0)
 * 버튼을 누르면 상향 하향 변경
 * 상향카운터 - 999를 넘으면 다시 000
 * 하향카운터 - 000보다 작아지면 999
 * 3자리만 사용 
 */

// 0에서 9까지 숫자 표현을 위한 세그먼트 a, b, c, d, e, f, g, dp의 패턴
byte patterns[] = { 0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6 };

// 자릿수 선택 핀 - 3자리만 출력
int digit_select_pin[] = {66, 67, 68};  

// 7세그먼트 모듈 연결 핀 ‘a, b, c, d, e, f, g, dp’ 순서
int segment_pin[] = {58, 59, 60, 61, 62, 63, 64, 65};

int SEGMENT_DELAY = 5; // 숫자 표시 사이의 시간 간격

// 풀다운
int button = 14; 
int state = 0; //state : 0 count 증가 state : 1 count 감소
int count = 0;

unsigned long time_previous, time_current;
boolean state_previous = false;

void setup() {
  for (int i = 0; i < 3; i++) { // 자릿수 선택 핀을 출력으로 설정
    pinMode(digit_select_pin[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) { // 세그먼트 제어 핀을 출력으로 설정
    pinMode(segment_pin[i], OUTPUT);
  }
  pinMode(button, INPUT); //Digital Button을 INPUT으로 설정
  time_previous = millis();
}

// 해당 자리에 숫자 하나를 표시하는 함수(위치, 출력할 숫자)
void show_digit(int pos, int number) { 
  for (int i = 0; i < 3; i++) {
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

// 3자리 7세그먼트 표시 장치에 3자리 숫자를 표시하는 함수
void show_3_digit(int number) {
  number = number % 1000; // 3자리로 제한
  int hundreads = number / 100; // 백 자리
  number = number % 100;
  int tens = number / 10; // 십 자리
  int ones = number % 10; // 일 자리
  show_digit(1, hundreads);
  delay(SEGMENT_DELAY);
  show_digit(2, tens);
  delay(SEGMENT_DELAY);
  show_digit(3, ones);
  delay(SEGMENT_DELAY);
}

void loop() {
  boolean state_current = digitalRead(button);
  time_current = millis();
  
  if(state == 0){
    if((state_previous == false)&& (state_current == false)){
      if (time_current - time_previous >= 100) {
        time_previous = time_current;
        count++;
      }
      if(count>=1000) {
        count = 0;
      }
      else{
        show_3_digit(count);
      } 
    }
    else{
      if((state_previous == true) && (state_current == false)){
        state_previous = false;
      }
      else if((state_previous == false) && (state_current == true)){
        state_previous = true;
        state = 1;
      }
    }
  }
  else{
    if((state_previous == true) &&(state_current == false)){
      if (time_current - time_previous >= 100) {
        time_previous = time_current;
        count--;
      }
      if(count<0) {
        count = 1000;
      }
      else{
        show_3_digit(count);
      } 
    }
    else{
      if((state_previous == false) && (state_current == false)){
        state_previous = true;
      }
      else if((state_previous == true) && (state_current == true)){
        state_previous = false;
        state = 0;
      }
    }
  }
}
