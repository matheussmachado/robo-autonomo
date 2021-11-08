#include <Arduino.h>
#include "motores_led.h"


//PROPÓSITO: EMULAR O COMPORTAMENTO DE UM MOTOR DC UTILIZANDO LEDS. 
//EM ÚLTIMA INSTÂNCIA, SERÃO UTILIZADAS AS FUNÇÕES PARA CONTROLAR O 
//MOVIMENTO FINAL DE UM MOTOR DC. PORTANTO, O NOME DC EM FUNÇÕES SERVIRÃO 
//PARA TESTAR O MOVIMENTO DE UM MOTOR AO RECEBER O FEEDBACK DO SENSOR DE DISTÂNCIA


// MOTORD UNITÁRIO

void iniciarMotorDC(struct MotorDC &motor, int pin_frontal, int pin_meio,int pin_traseiro) {
  motor.frontal = pin_frontal;
  motor.meio = pin_meio;
  motor.traseiro = pin_traseiro;
}

void reiniciaMotor(struct MotorDC motor) {
  digitalWrite(motor.frontal, LOW);
  digitalWrite(motor.meio, LOW);
  digitalWrite(motor.traseiro, LOW);
}

//
