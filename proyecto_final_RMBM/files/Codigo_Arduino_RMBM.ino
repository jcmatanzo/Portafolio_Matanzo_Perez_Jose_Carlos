#include <Servo.h>
#include <SoftwareSerial.h>


#define Garra 13
#define Altura 12
#define Adelante_atras2 7
#define Direccion 8


#define Vel_motor_A 5
#define Vel_motor_B 6
#define Vel_motor_C 3
#define Vel_motor_D 11

#define motor_A 2
#define motor_B 4
#define motor_c A3
#define motor_c2 A0
#define motor_d A1
#define motor_d2 A2



SoftwareSerial bluetooth(0, 1);  //(BT_RX, BT_TX)

// Servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

// Variables para almacenar las posiciones de los servos
int pos1 = 90;//garra lista de 60 a 180 grados
int pos2 = 90; //direccion
int pos3 = 0;//altura bien
int pos4 = 0;// 0 aa 90

void setup() {
  // Inicia la comunicación serial
  Serial.begin(9600);
  bluetooth.begin(9600);

  // motores
  pinMode(motor_A, OUTPUT);
  pinMode(motor_B, OUTPUT);
  pinMode(motor_c, OUTPUT);
  pinMode(motor_c2, OUTPUT);
  pinMode(motor_d, OUTPUT);
  pinMode(motor_d2, OUTPUT);
  pinMode(Vel_motor_A, OUTPUT);
  pinMode(Vel_motor_B, OUTPUT);
  pinMode(Vel_motor_C, OUTPUT);
  pinMode(Vel_motor_D, OUTPUT);

  // Asigna los servos a los pines digitales
  servo1.attach(Garra);
  servo2.attach(Direccion);
  servo3.attach(Altura);
  servo5.attach(Adelante_atras2);

  // Posición inicial de los servos
  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo5.write(pos4);
}

void loop() {
  // Verifica si hay datos disponibles desde el Bluetooth
  if (bluetooth.available() >= 2) {
    // El Primer byte identifica el servo (1-4)
    int nservo = bluetooth.read();
    // El Segundo byte es el ángulo (0-180)
    int pos = bluetooth.read();

    // Actualiza la posición del servo correspondiente
    switch (nservo) {
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
        servo5.write(pos4);
        break;
      case 5:  //diagonal arriba izquierda
        digitalWrite(motor_d, HIGH);
        digitalWrite(motor_d2, LOW);
        digitalWrite(motor_A, LOW);
        analogWrite(Vel_motor_A, pos);
        analogWrite(Vel_motor_B, 0);
        analogWrite(Vel_motor_C, 0);
        analogWrite(Vel_motor_D, pos);
        break;
      case 6:  //arriba
        digitalWrite(motor_d, HIGH); //ADELANTE
        digitalWrite(motor_d2, LOW); //ATRAS
        digitalWrite(motor_c, LOW); // ATRAS
        digitalWrite(motor_c2, HIGH); // ADELANTE
        digitalWrite(motor_A, LOW); //LOW ADELANTE
        digitalWrite(motor_B, LOW); // LOW ADELANTE
        analogWrite(Vel_motor_A, pos);
        analogWrite(Vel_motor_D, pos);
        analogWrite(Vel_motor_B, pos);
        analogWrite(Vel_motor_C, pos);
        break;
      case 7:  //diagonal arriba derecha
        digitalWrite(motor_c, LOW);
        digitalWrite(motor_c2, HIGH);
        digitalWrite(motor_B, LOW);
        analogWrite(Vel_motor_B, pos);
        analogWrite(Vel_motor_C, pos);
        analogWrite(Vel_motor_A, 0);
        analogWrite(Vel_motor_D, 0);
        break;
      case 8:  //izquierda
        digitalWrite(motor_d, HIGH); //ADELANTE
        digitalWrite(motor_d2, LOW); //ATRAS
        digitalWrite(motor_c, HIGH); // ATRAS
        digitalWrite(motor_c2, LOW); // ADELANTE
        digitalWrite(motor_A, LOW); //LOW ADELANTE
        digitalWrite(motor_B, HIGH); // LOW ADELANTE
        analogWrite(Vel_motor_A, pos);
        analogWrite(Vel_motor_D, pos);
        analogWrite(Vel_motor_B, pos);
        analogWrite(Vel_motor_C, pos);
      case 9:  //giro contra
        digitalWrite(motor_d, HIGH); //ADELANTE
        digitalWrite(motor_d2, LOW); //ATRAS
        digitalWrite(motor_c, HIGH); // ATRAS
        digitalWrite(motor_c2, LOW); // ADELANTE
        digitalWrite(motor_A, HIGH); //LOW ADELANTE
        digitalWrite(motor_B, LOW); // LOW ADELANTE
        analogWrite(Vel_motor_A, pos);
        analogWrite(Vel_motor_D, pos);
        analogWrite(Vel_motor_B, pos);
        analogWrite(Vel_motor_C, pos);
        break;
      case 10:  //giro manecillas
        digitalWrite(motor_d, LOW); //ADELANTE
        digitalWrite(motor_d2, HIGH); //ATRAS
        digitalWrite(motor_c, LOW); // ATRAS
        digitalWrite(motor_c2, HIGH); // ADELANTE
        digitalWrite(motor_A, LOW); //LOW ADELANTE
        digitalWrite(motor_B, HIGH); // LOW ADELANTE
        analogWrite(Vel_motor_A, pos);
        analogWrite(Vel_motor_D, pos);
        analogWrite(Vel_motor_B, pos);
        analogWrite(Vel_motor_C, pos);
        break;
      case 11:  // derecha
        digitalWrite(motor_d, LOW); //ADELANTE
        digitalWrite(motor_d2, HIGH); //ATRAS
        digitalWrite(motor_c, LOW); // ATRAS
        digitalWrite(motor_c2, HIGH); // ADELANTE
        digitalWrite(motor_A, HIGH); //LOW ADELANTE
        digitalWrite(motor_B, LOW); // LOW ADELANTE
        analogWrite(Vel_motor_A, pos);
        analogWrite(Vel_motor_D, pos);
        analogWrite(Vel_motor_B, pos);
        analogWrite(Vel_motor_C, pos);
        break;
      case 12:  //diagonal abajo izquierda
        digitalWrite(motor_c, HIGH);
        digitalWrite(motor_c2, LOW);
        digitalWrite(motor_B, HIGH);
        analogWrite(Vel_motor_B, pos);
        analogWrite(Vel_motor_C, pos);
        analogWrite(Vel_motor_A, 0);
        analogWrite(Vel_motor_D, 0);
        break;
      case 13:  // abajo
        digitalWrite(motor_d, LOW);
        digitalWrite(motor_d2, HIGH);
        digitalWrite(motor_c, HIGH);
        digitalWrite(motor_c2, LOW);
        digitalWrite(motor_A, HIGH);
        digitalWrite(motor_B, HIGH);
        analogWrite(Vel_motor_A, pos);
        analogWrite(Vel_motor_D, pos);
        analogWrite(Vel_motor_B, pos);
        analogWrite(Vel_motor_C, pos);
        break;
      case 14:  // diagonal abajo derecha
        digitalWrite(motor_d, LOW);
        digitalWrite(motor_d2, HIGH);
        digitalWrite(motor_A, HIGH);
        analogWrite(Vel_motor_A, pos);
        analogWrite(Vel_motor_B, 0);
        analogWrite(Vel_motor_C, 0);
        analogWrite(Vel_motor_D, pos);
        break;
      case 15: //detener
        digitalWrite(motor_c, LOW);
        digitalWrite(motor_c2, LOW);
        digitalWrite(motor_d, LOW);
        digitalWrite(motor_d2, LOW);
        analogWrite(Vel_motor_A, 0);
        analogWrite(Vel_motor_B, 0);
      case 16:  //izquierda
        digitalWrite(motor_d, HIGH); //ADELANTE
        digitalWrite(motor_d2, LOW); //ATRAS
        digitalWrite(motor_c, HIGH); // ATRAS
        digitalWrite(motor_c2, LOW); // ADELANTE
        digitalWrite(motor_A, LOW); //LOW ADELANTE
        digitalWrite(motor_B, HIGH); // LOW ADELANTE
        analogWrite(Vel_motor_A, pos);
        analogWrite(Vel_motor_D, pos);
        analogWrite(Vel_motor_B, pos);
        analogWrite(Vel_motor_C, pos);
    }
  }


}