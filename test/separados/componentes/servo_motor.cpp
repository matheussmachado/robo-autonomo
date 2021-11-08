/*
#include <Arduino.h>
#include <Servo.h>
#define LADO_ESQUERDO 180 //SENTIDO OESTE
#define LADO_FRONTAL 90 //SENTIDO NORTE
#define LADO_DIREITO 0 // SENTIDO LESTE

Servo servo;

void setupServo() {
  servo.attach(3);
  servo.write(LADO_FRONTAL);
  delay(1000);
}

void setup() {
  setupServo();
}

void girarSensor(int lado) {
  servo.write(lado);
  delay(2000);
}

void loop() {
  girarSensor(LADO_ESQUERDO);
  girarSensor(LADO_DIREITO);
  girarSensor(LADO_FRONTAL);
}
*/