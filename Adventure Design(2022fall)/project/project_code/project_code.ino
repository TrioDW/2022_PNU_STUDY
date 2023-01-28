#include <Adafruit_Fingerprint.h>
#include <pitches.h>
#include <LiquidCrystal.h>

#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
SoftwareSerial mySerial(2, 3);

#else
#define mySerial Serial1
#endif

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
int RGB_LED[] = {6, 7, 8};
int RGB_LED_Rain[] = {2, 3, 4};
String member_list[4] = {"Kim Dae Wook", "Park Yu Hyeon", "Kim Dong In"};
int speakerPin = A0;
int noteDuration = 4; 
LiquidCrystal lcd(44, 45, 46, 47, 48, 49);

void setup() {
  Serial.begin(9600);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");

  finger.begin(57600);
  delay(5);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  finger.getParameters();
  finger.getTemplateCount();

  //for RGB default setting
  for(int i = 0; i < 3; i++){
    pinMode(RGB_LED[i], OUTPUT);
    pinMode(RGB_LED_Rain[i], OUTPUT);
    digitalWrite(RGB_LED[i], LOW);
    digitalWrite(RGB_LED_Rain[i], LOW);
  }

  //for LCD default setting
  lcd.begin(16, 2);
  lcd.print("Put finger");
  lcd.setCursor(0, 1);
  lcd.print("on water sensor");
  pinMode(A1, INPUT);

}

void loop()  
{
  if(rain_sensor_test() == 2){ //빗방울에 물기가 감지 안됐을때
    digitalWrite(RGB_LED_Rain[0], LOW);
    digitalWrite(RGB_LED_Rain[1], HIGH);
    digitalWrite(RGB_LED_Rain[2], LOW); 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No Humidity");
    lcd.setCursor(0, 1);
    lcd.print("Detected!");
    delay(500);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Put finger");
    lcd.setCursor(0, 1);
    lcd.print("on finger seosor");

    getFingerprintID(); //지문인식센서 동작하게 해주는 전체 총괄 함수
    delay(100);   
  }
  else if(rain_sensor_test() == 0){ //빗방울에 물기가 감지 됐을때
    lcd.clear();
    lcd.print("Water Detected");
    delay(300);
    lcd.clear();
    lcd.print("Try again");
    lcd.setCursor(0, 1);
    lcd.print("after reset");
    while(1){ //이 while문을 못빠져나와서 지문인식센서가 더이상 동작이 안됨
      digitalWrite(RGB_LED_Rain[2], HIGH);
      digitalWrite(RGB_LED_Rain[1], LOW);
      digitalWrite(RGB_LED_Rain[0], LOW);
    }
  }
}

int rain_sensor_test(){ //빗방울 감지 했을때 처리해주는 함수
  int rain = analogRead(A1);

  if (rain < 600){ //물기 감지 되면
    delay(100);
    return 0;
  }

  else if (960 < rain && rain< 1010){ //물기 없는 손가락 올려진다면
    for(int i = 0; i < 3; i++){
      digitalWrite(RGB_LED_Rain[i], LOW);
    }
    return 2; 
    delay(10000); 
  }
  return 1;
}


void success_sound(){ //성공 음
  int melody[] = { // 학교 종 멜로디, 0은 쉼표
  NOTE_C5, NOTE_E5, NOTE_G5, NOTE_C6, 0};

  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(int); thisNote++) {
    int noteLength = 1500 / noteDuration;
    tone(speakerPin, melody[thisNote], noteLength);
    delay(noteLength);
    noTone(speakerPin);
  }
}

void fail_sound(){ //실패 음
  int melody[] = { // 학교 종 멜로디, 0은 쉼표
  NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, 0};

  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(int); thisNote++) {
    int noteLength = 1000 / noteDuration;
    tone(speakerPin, melody[thisNote], noteLength);
    delay(noteLength);
    noTone(speakerPin);
  }
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!
  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK converted!
  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
    lcd.clear();
    lcd.print("Hello,");
    lcd.setCursor(0, 1);
    lcd.print(member_list[finger.fingerID - 1]); //구성원 이름 출력
    digitalWrite(RGB_LED[1], HIGH);
    success_sound();
    digitalWrite(RGB_LED[1], LOW);
    lcd.clear();
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    lcd.print("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    lcd.clear();
    lcd.print("Did not find a");
    lcd.setCursor(0, 1);
    lcd.print("match!");
    digitalWrite(RGB_LED[2], HIGH);
    fail_sound();
    digitalWrite(RGB_LED[2], LOW);
    lcd.clear();
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK) return -1;
  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) return -1;
  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK) return -1;

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID;
}
