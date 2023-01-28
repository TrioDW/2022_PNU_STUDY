// LAB11-1-4 (p.15)

// 적외선 센
int motionPin = 8;

// 초음파 센서
int trigPin = 3;
int echoPin = 2;

// LED
int led1Pin = 11;
int led2Pin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(motionPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {
  int motion = digitalRead(motionPin);
  int led1Bright = 0;

  // 초음파 센서로 거리 측정
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  float duration = pulseIn(echoPin, HIGH);
  float distance = duration * 340 / 10000 / 2;
  
  Serial.println(String("Distance(cm): ") + distance);
  
  // 거리 > 100 : LED OFF, 거리 < 100 : 거리가 가까워질수록 밝게 
  if (distance > 100) {
    led1Bright = 0;
  }
  else {
    led1Bright = map(distance, 100, 0, 0, 255);
  }
  Serial.println(led1Bright);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
  analogWrite(led1Pin, led1Bright);

  // 모션이 감지되면 LED ON
  if (motion == 1) {
    Serial.println("Motion detected");
    digitalWrite(led2Pin, HIGH);
  }
   else {
    digitalWrite(led2Pin, LOW);
  }
  delay(500);
}
