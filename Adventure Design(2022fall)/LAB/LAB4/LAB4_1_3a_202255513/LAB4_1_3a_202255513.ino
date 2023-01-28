// LAB4_1_3a_202255513

void setup() {
  Serial.begin(9600); // 시리얼 포트 초기화
}

void loop() {
  int state = 1, len = 0; 
  char buffer[128];
  
  while (true) {
    if (state == 1) {
      Serial.print("Enter a String --> ");
      state = 2; 
      }
      
      while (Serial.available()) {
        char data = Serial.read();
        if (data == '\n') {
        // 개행 문자 ‘\n’을 만날 때까지 읽음 
          buffer[len] = '\0';
          String in_str = buffer; 
          Serial.println(in_str + " [" + in_str.length()+"]"); 
          state = 1;
          len = 0;
          break;
        }
        buffer[len++] = data;
      } 
  }
}
