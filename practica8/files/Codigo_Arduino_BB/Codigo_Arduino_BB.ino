#include <Servo.h>
#include <SoftwareSerial.h>


SoftwareSerial bluetooth(2,3);// Pines HC05

// Servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Variables para almacenar posiciones
int pos1 = 90;
int pos2 = 90;
int pos3 = 90;
int pos4 = 0;

void setup() {
  // Comunicación serial
  Serial.begin(9600);
  bluetooth.begin(9600);
  
  // Asignar pines de servos
  servo1.attach(8);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);
  
  // Posición inicial
  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo4.write(pos4);
}

void loop() {
  // Datos disponibles
  if (bluetooth.available() >= 2) {
    // Primer byte servo (1-4)
    int nservo = bluetooth.read();
    // Segundo byte ángulo (0-180)
    int pos = bluetooth.read();
    
    // Actualizar posición
    switch(nservo) {
      case 1:
        pos1 = pos;
        servo1.write(pos1);
        break;
      case 2:
        pos2 = pos;
        servo2.write(pos2);
        break;
      case 3:
        pos3 = pos;
        servo3.write(pos3);
        break;
      case 4:
        pos4 = pos;
        servo4.write(pos4);
        break;
    }
    
    Serial.print("Servo ");
    Serial.print(nservo);
    Serial.print(": ");
    Serial.println(pos);
  }
}

