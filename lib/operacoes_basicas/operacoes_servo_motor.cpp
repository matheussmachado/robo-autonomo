#include <Arduino.h>
#include <Servo.h>
#include "operacoes.h"

Servo servo;

void setupServoMotor() {
  servo.attach(PIN_SERVO_MOTOR);
  servo.write(LADO_FRONTAL);
  delay(500);
}

void posicionarEixoDoServo(int angulo) {
  servo.write(angulo);
}
