/*
#include <Arduino.h>

#define PIN_MOTOR_DC_ESQUERDO_POSITIVO 7
#define PIN_MOTOR_DC_ESQUERDO_NEGATIVO 8
#define PIN_MOTOR_DC_ESQUERDO_ENABLE 5
#define PIN_MOTOR_DC_DIREITO_POSITIVO 2
#define PIN_MOTOR_DC_DIREITO_NEGATIVO 4
#define PIN_MOTOR_DC_DIREITO_ENABLE 3
#define PIN_SENSOR_ULTRASSONIC_ECHO 12
//#define PIN_SENSOR_ULTRASSONIC_TRIGGER 13

#define SENTIDO_FRONTAL HIGH
#define SENTIDO_TRASEIRO LOW
#define DISTANCIA_FRONTAL_MINIMA 3 // CENTÍMETROS
#define VEL_PADRAO 200
#define VEL_MOTOR_ESQUERDA_OPCIONAL 200
#define VEL_MOTOR_DIREITA_OPCIONAL 130

//INICIO SENSOR ULTRASSONICO *************************************************

float medirDistanciaCm() {
  //FUNÇÃO BASEADA NO SENSOR HC-SR04
  float duracaoPulsoEcho; //duração em micro segundos
  float distanciaCm;
  digitalWrite(PIN_SENSOR_ULTRASSONIC_TRIGGER, HIGH);
  delayMicroseconds(10); //10 é o valor informado pelo fabricante
  digitalWrite(PIN_SENSOR_ULTRASSONIC_TRIGGER, LOW);
  duracaoPulsoEcho = pulseIn(PIN_SENSOR_ULTRASSONIC_ECHO, HIGH);
  distanciaCm = duracaoPulsoEcho/58; //58 é o valor informado pelo fabricante, para a conversão em centímetro da duração do pulso
  return distanciaCm;
  }  

void setupSensorUltrassonico() {
  pinMode(PIN_SENSOR_ULTRASSONIC_TRIGGER, OUTPUT);
  pinMode(PIN_SENSOR_ULTRASSONIC_ECHO, INPUT);
  digitalWrite(PIN_SENSOR_ULTRASSONIC_TRIGGER, LOW);

}
//FIM SENSOR ULTRASSONICO ***************************************************

//INICIO MOTORES DC *********************************************************

struct MotorDC {
  unsigned int positivo;
  unsigned int negativo;
  unsigned int enable;
  unsigned int velocidade;
};

// MOTOR DC UNITÁRIO GENÉRICO

void iniciarMotorDC(struct MotorDC &motor, int pin_positivo, int pin_negativo,int pin_enable, int vel=VEL_PADRAO) {
  motor.positivo = pin_positivo;
  motor.negativo = pin_negativo;
  motor.enable = pin_enable;
  motor.velocidade = vel;
}

void moverMotorDC(struct MotorDC motor, int sentido) {
  analogWrite(motor.enable, motor.velocidade);
  digitalWrite(motor.positivo, sentido);
  digitalWrite(motor.negativo, !sentido);  
}

void pararMotorDC(struct MotorDC motor) {
  digitalWrite(motor.positivo, LOW);
  digitalWrite(motor.negativo, LOW);
}

//

//CONJUNTO DOS DOIS MOTORES DC DECLARADOS

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
}

void manobrarEsquerda() {
  moverMotorDC(motorEsquerdo, SENTIDO_TRASEIRO);
  moverMotorDC(motorDireito, SENTIDO_FRONTAL);
}

void manobrarDireita() {
  moverMotorDC(motorEsquerdo, SENTIDO_FRONTAL);
  moverMotorDC(motorDireito, SENTIDO_TRASEIRO);
}

//


//FIM MOTORES DC *********************************************************

bool verificarObstaculoFrontal() {
  if (medirDistanciaCm() >= DISTANCIA_FRONTAL_MINIMA) {
    return false;
  }
  return true;
}

void setup() {
  setupMotoresDC();
  setupSensorUltrassonico();
}

bool obstaculo;

void loop() {
  obstaculo = verificarObstaculoFrontal();  
  if (obstaculo == false) {
      locomover(SENTIDO_FRONTAL);
      return;
  }
  frear();
}
*/