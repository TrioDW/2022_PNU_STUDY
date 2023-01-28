// LAB4_1_2_202255513

void setup() {
  Serial.begin(9600);                                     // 시리얼 포트 초기화
}

void loop() {
  // 정렬할 문자열 배열
  String str[5] = {"abc", "ABC", "!@#", "라라라", "123"};

  // 문자열 정렬
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 5; j++) {
      int compare = str[i].compareTo(str[j]);
      if (compare > 0) {                                   // 오름차순으로 정렬
        String temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }
  
  // 정렬된 문자열 출력3
  for (int i = 0; i < 5; i++) {
    Serial.println(String(i) + " : " + str[i]);
  }
  
  while (true);

  // 정렬할 문자열의 정렬과정을 설명하시오. 11, 12 ~ 55 비교하면서 자리를 바꾸거나 유지한다.
  // 내림차순으로 정렬을 하려면 ? compare 변수가 음수가 되도록 '<'로 부등호 방향을 바꾸어준다.
  // CompareTo 함수가 무엇인가 ? 두 문자열에 있는 문자를 차례로 비교하여 두 문자열이 동일한지 여부를 식별한다.
}
