// LAB2_2_3_202255513

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    byte data = Serial.read();

    Serial.print("Echo back : ");
    Serial.write(data); // 문자 출력
    Serial.print(" ");
    Serial.println(data); // ASCII 값 출력
  } 
}
