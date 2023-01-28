// HW2_202255513_김대욱

int flag = 1;

void setup() {
  Serial.begin(9600);
}

void loop() {

  if (flag) {
    Serial.println("Enter 2 Integers to add");
    flag = 0;
  }
  
  while(Serial.available() == 0) {}
  int num1 = Serial.parseInt();

  while(Serial.available() == 0) {}
  int num2 = Serial.parseInt();

  int sum = num1 + num2;

  Serial.print(num1);
  Serial.print(" + ");
  Serial.print(num2);
  Serial.print(" = ");
  Serial.println(sum);

  flag = 1;
}
