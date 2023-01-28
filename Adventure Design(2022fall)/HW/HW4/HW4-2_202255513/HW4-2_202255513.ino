// HW4-2_202255513

int pins_LED[] = {2, 3, 4, 5};

// 14번에 풀다운 저항
int pins_button = 14;

// 불이 켜지는 LED 결정
int LED_patterns[] = {0b0001, 0b0010, 0b0100, 0b1000};

// 버튼을 누르면 True, 안누르면 False
boolean state_before = false;

// state = 0 이면, 1 > 2 > 3 > 4 > 1 ...
// state = 1 이면, 4 > 3 > 2 > 1 > 4 ...

// index는 LED 배열 index 이다.

int state = 0, index = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pins_button, INPUT);

  for (index = 0; index < 4; index++) {
    pinMode(pins_LED[index], OUTPUT);
  }
}

void loop() {
  boolean state_now = digitalRead(pins_button);

  if (state == 0) {
    if (state_now == true && state_before == false) {
      index -= 2;
      state_before = true;
      state = 1;
    }
    else {
      if (state_now == false && state_before == true) {
        state_before = false;
      }
      if (index == 4) {
        index = 0;
      }

      if (index < 4) {
        for (int i = 0; i < 4; i++) {
          digitalWrite(pins_LED[i], bitRead(LED_patterns[index], i));
        }
        index++;
        delay(500);
      }
    }
  }

  if (state == 1) {
    if (state_now == true && state_before == false) {
      index += 2;
      state_before = true;
      state = 0;
    }
    else {
      if (state_now == false && state_before == true) {
        state_before = false;
      }
      if (index == -1) {
        index = 3;
      }
      if (index >= 0) {
        for (int i = 0; i < 4; i++) {
          digitalWrite(pins_LED[i], bitRead(LED_patterns[index], i));
        }
        index--;
        delay(500);
      }
    }
  }
}
