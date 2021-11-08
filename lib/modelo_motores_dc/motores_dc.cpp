#include <Arduino.h>
#include "motores_dc.h"


void iniciarMotorDC(struct MotorDC &motor, int pin_positivo, int pin_negativo, int pin_enable, int vel=VEL_PADRAO) {
  motor.positivo = pin_positivo;
  motor.negativo = pin_negativo;
  motor.enable = pin_enable;
  motor.velocidade = vel;
}

void moverMotorDC(struct MotorDC motor, int sentido) {
  //BASEADO NO MOVIMENTO LINEAR QUE O MOTOR DC PROPORCIONA E NÃO ÂNGULAR,
  //TENDO COMO REFERÊNCIA O TERMINAL POSITIVO DO MOTOR NO ENVIO DO SINAL
  analogWrite(motor.enable, motor.velocidade);
  digitalWrite(motor.positivo, sentido);
  digitalWrite(motor.negativo, !sentido);  
}

void pararMotorDC(struct MotorDC motor) {
  digitalWrite(motor.positivo, LOW);
  digitalWrite(motor.negativo, LOW);
}
