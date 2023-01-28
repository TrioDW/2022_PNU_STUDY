// HW7-2_202255513

/*
 * 가변저항으로 음표 재생
 * 가변저항에 가해지는 전압을 9단계로 나누고 각 구간에서 "무음 도 레 미 파 솔 라 시 도" 를 연주
 */

#include <pitches.h>

int vResistor = 56; // 가변저항 연결핀
int speakerPin = 57; // 스피커 연결핀

//adc가 1017이상이 되면 Note가 9가 되서 무음이 된다

int interval = 1024 / 9;

//무음 도 레 미 파 솔 라 시 도
int melody[] = {
  0, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6
};
int noteDuration = 4; // 4분 음표

void setup() {
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(vResistor);
  Serial.print("ADC : ");
  Serial.print(reading);
  Serial.println();
  
  int thisNote = reading / interval;
  //9단계로 정확하게 나눌수가 없어 ADC가 1017이상은 8로 취급한다
  
  if (thisNote >= 9){
    thisNote = 8;
  }
  
  int noteLength = 1000 / noteDuration; 
  
  tone(speakerPin, melody[thisNote], noteLength);
  delay(noteLength);
  noTone(speakerPin);
}
