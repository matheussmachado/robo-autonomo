/*
#include <Arduino.h>
#include "operacoes.h"

struct MotorDC motorEsquerdo;
struct MotorDC motorDireito;

void setupMotoresDC() {
  pinMode(PIN_MOTOR_DC_ESQUERDO_POSITIVO, OUTPUT);
  pinMode(PIN_MOTOR_DC_ESQUERDO_NEGATIVO, OUTPUT);
  pinMode(PIN_MOTOR_DC_DIREITO_POSITIVO, OUTPUT);
  pinMode(PIN_MOTOR_DC_DIREITO_NEGATIVO, OUTPUT);
  iniciarMotorDC(motorDireito, PIN_MOTOR_DC_DIREITO_POSITIVO, PIN_MOTOR_DC_DIREITO_NEGATIVO, PIN_MOTOR_DC_DIREITO_ENABLE);
  iniciarMotorDC(motorEsquerdo, PIN_MOTOR_DC_ESQUERDO_POSITIVO, PIN_MOTOR_DC_ESQUERDO_NEGATIVO, PIN_MOTOR_DC_ESQUERDO_ENABLE);  
}

void locomover(int sentido) {
  moverMotorDC(motorEsquerdo, sentido);
  moverMotorDC(motorDireito, sentido);
}

void frear() {
  pararMotorDC(motorEsquerdo);
  pararMotorDC(motorDireito);
  delay(500);
}

void manobrarLateral(int lado) {
  if (lado == LADO_DIREITO) {
    moverMotorDC(motorEsquerdo, SENTIDO_FRONTAL);
    moverMotorDC(motorDireito, SENTIDO_TRASEIRO);
  }
  else if (lado == LADO_ESQUERDO){
    moverMotorDC(motorEsquerdo, SENTIDO_TRASEIRO);
    moverMotorDC(motorDireito, SENTIDO_FRONTAL);
  }
}
*/