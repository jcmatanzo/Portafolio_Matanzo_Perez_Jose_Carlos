#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int potPin1 = A0;
int potPin2 = A1;
int potPin3 = A2;
int potPin4 = A3;

int potValue1;
int potValue2;
int potValue3;
int potValue4;

int stablePotRead(int potPin) {
  int total = 0;

  for (int i = 0; i < 10; i++) {
    total += analogRead(potPin);
    delay(10); 
  }
  return total / 10; 
}

void setup() {

  servo1.attach(13); // Pin 13 para el servo1
  servo2.attach(12); // Pin 12 para el servo2
  servo3.attach(11); // Pin 11 para el servo3
  servo4.attach(10); // Pin 10 para el servo4

  Serial.begin(9600);

  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);

  delay(500);  
}

void loop() {

  potValue1 = stablePotRead(potPin1);
  potValue2 = stablePotRead(potPin2);
  potValue3 = stablePotRead(potPin3);
  potValue4 = stablePotRead(potPin4);

  int servoPos1 = map(potValue1, 0, 1023, 0, 180);
  int servoPos2 = map(potValue2, 0, 1023, 0, 180);
  int servoPos3 = map(potValue3, 0, 1023, 0, 180);
  int servoPos4 = map(potValue4, 0, 1023, 0, 180);

  servo1.write(servoPos1);
  servo2.write(servoPos2);
  servo3.write(servoPos3);
  servo4.write(servoPos4);
  
  Serial.print("Servo 1: "); Serial.println(servoPos1);
  Serial.print("Servo 2: "); Serial.println(servoPos2);
  Serial.print("Servo 3: "); Serial.println(servoPos3);
  Serial.print("Servo 4: "); Serial.println(servoPos4);

  delay(15);
}
