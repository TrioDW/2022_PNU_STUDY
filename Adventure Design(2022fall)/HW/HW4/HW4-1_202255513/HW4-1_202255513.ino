// HW4-1_202255513

void setup() {
  Serial.begin(9600);
}

void loop() {
  int flag = 1, index = 0;
  char buffer[128];
  String str[5];

  while (index < 5) {
    if (flag == 1) {
      Serial.print("Enter the ");
      Serial.print(index+1);
      Serial.print("th Word -->");
      flag = 0;
    }
  
    while(Serial.available()) {
      int len = Serial.readBytesUntil('\n', buffer, 127);
      if (len > 0) {
        buffer[len] = '\0';
        str[index++] = String(buffer);
        Serial.println(String(buffer));
        flag = 1;
        break;
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 5; j++) {
      int compare = str[i].compareTo(str[j]);
      if (compare > 0) {
        String temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }
  Serial.println("After Sorting");
  for (int i = 0; i < 5; i++) {
    Serial.println(str[i]);
  }
}
