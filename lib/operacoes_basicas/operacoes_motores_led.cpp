/*INSTRUÇÕES: 
Comentar todo o código em operacoes_motores_dc.cpp e substituir o #include "motores_dc.h" 
por #include "motores_led.h" em "operacoes.h" ao utilizar esse código. Fazer o inverso para utilizar o código "operacoes_motores_led.cpp"
*/

#include <Arduino.h>
#include "operacoes.h"

//MESMOS PINOS QUE O MOTOR DC
#define PIN_MOTOR_LED_ESQUERDO_FRONTAL 7
#define PIN_MOTOR_LED_ESQUERDO_TRASEIRO 8
#define PIN_MOTOR_LED_ESQUERDO_MEIO 5
#define PIN_MOTOR_LED_DIREITO_FRONTAL 2
#define PIN_MOTOR_LED_DIREITO_TRASEIRO 4
#define PIN_MOTOR_LED_DIREITO_MEIO 3

struct MotorDC motorEsquerdo;
struct MotorDC motorDireito;

void setupMotoresDC() {
  pinMode(PIN_MOTOR_LED_ESQUERDO_FRONTAL, OUTPUT);
  pinMode(PIN_MOTOR_LED_ESQUERDO_MEIO, OUTPUT);
  pinMode(PIN_MOTOR_LED_ESQUERDO_TRASEIRO, OUTPUT);
  pinMode(PIN_MOTOR_LED_DIREITO_FRONTAL, OUTPUT);
  pinMode(PIN_MOTOR_LED_DIREITO_MEIO, OUTPUT);
  pinMode(PIN_MOTOR_LED_DIREITO_TRASEIRO, OUTPUT);
  iniciarMotorDC(motorEsquerdo, PIN_MOTOR_LED_ESQUERDO_FRONTAL, PIN_MOTOR_LED_ESQUERDO_MEIO, PIN_MOTOR_LED_ESQUERDO_TRASEIRO);
  iniciarMotorDC(motorDireito, PIN_MOTOR_LED_DIREITO_FRONTAL, PIN_MOTOR_LED_DIREITO_MEIO, PIN_MOTOR_LED_DIREITO_TRASEIRO);
}

void reiniciaMotores() {
  reiniciaMotor(motorEsquerdo);
  reiniciaMotor(motorDireito);
}

void locomover(int sentido) {
  reiniciaMotores();
  if (sentido == SENTIDO_FRONTAL) {
    digitalWrite(motorEsquerdo.frontal, HIGH);
    digitalWrite(motorDireito.frontal, HIGH);
  } else {
    digitalWrite(motorEsquerdo.traseiro, HIGH);
    digitalWrite(motorDireito.traseiro, HIGH);
  }
}

void frear() {
  reiniciaMotores();
  digitalWrite(motorEsquerdo.meio, HIGH);
  digitalWrite(motorDireito.meio, HIGH);
  delay(500);
}

void manobrarLateral(int lado) {
  reiniciaMotores();
  if (lado == LADO_DIREITO) {
    digitalWrite(motorEsquerdo.frontal, HIGH);
    digitalWrite(motorDireito.traseiro, HIGH);  
  }
  else if (lado == LADO_ESQUERDO) {
    digitalWrite(motorEsquerdo.traseiro, HIGH);
    digitalWrite(motorDireito.frontal, HIGH);
  }
}
