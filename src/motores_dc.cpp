#include <Arduino.h> //NÃO USAR ESSA LINHA SE ESTIVER USANDO O ARDUINO IDE OU ALGUM SIMULADOR ONLINE

#define PIN_MOTOR_DC_ESQUERDA_POSITIVO 5
#define PIN_MOTOR_DC_ESQUERDA_NEGATIVO 6
#define PIN_MOTOR_DC_DIREITA_POSITIVO 9
#define PIN_MOTOR_DC_DIREITA_NEGATIVO 10

#define MOVIMENTO_FRONTAL HIGH
#define MOVIMENTO_TRASEIRO LOW



struct MotorDC {
  unsigned int positivo;
  unsigned int negativo;
};

struct MotorDC motorEsquerda;
struct MotorDC motorDireita;


void setupMotoresDC() {
  pinMode(PIN_MOTOR_DC_ESQUERDA_POSITIVO, OUTPUT);
  pinMode(PIN_MOTOR_DC_ESQUERDA_NEGATIVO, OUTPUT);
  pinMode(PIN_MOTOR_DC_DIREITA_POSITIVO, OUTPUT);
  pinMode(PIN_MOTOR_DC_DIREITA_NEGATIVO, OUTPUT);
  motorEsquerda.positivo = PIN_MOTOR_DC_ESQUERDA_POSITIVO;
  motorEsquerda.negativo = PIN_MOTOR_DC_ESQUERDA_NEGATIVO;
  motorDireita.positivo = PIN_MOTOR_DC_DIREITA_POSITIVO;
  motorDireita.negativo = PIN_MOTOR_DC_DIREITA_NEGATIVO;

}

void setup() {
  Serial.begin(9000);
  setupMotoresDC();
}

// MOTOR DC UNITÁRIO

void moverMotorDC(struct MotorDC motor, int sentido) {
  digitalWrite(motor.positivo, sentido);
  digitalWrite(motor.negativo, !sentido);  
}

void pararMotorDC(struct MotorDC motor) {
  digitalWrite(motor.positivo, LOW);
  digitalWrite(motor.negativo, LOW);
}
//

//CONJUNTO DOS DOIS MOTORES DC

void moverMotoresDCParaFrente() {
  moverMotorDC(motorEsquerda, MOVIMENTO_FRONTAL);
  moverMotorDC(motorDireita, MOVIMENTO_FRONTAL);
}

void moverMotoresDCParaTras() {
  moverMotorDC(motorEsquerda, MOVIMENTO_TRASEIRO);
  moverMotorDC(motorDireita, MOVIMENTO_TRASEIRO);
}

void pararMotoresDC() {
  pararMotorDC(motorEsquerda);
  pararMotorDC(motorDireita);
}
//

//TESTES DE VISTA

void testeMoverMotorDireitaParaFrenteEPararMotor() {
  Serial.println("TESTE: MOVER MOTOR DA DIREITA PARA FRENTE E PARAR MOTOR\n");
  moverMotorDC(motorDireita, MOVIMENTO_FRONTAL);
  delay(5000);
  pararMotoresDC();
  delay(2000);
}

void testeMoverMotorEsquerdaParaFrenteEPararMotor() {
  Serial.println("TESTE: MOVER MOTOR DA ESQUERDA PARA FRENTE E PARAR MOTOR\n");
  moverMotorDC(motorEsquerda, MOVIMENTO_FRONTAL);
  delay(5000);
  pararMotoresDC();
  delay(2000);
}

void testeMoverMotoresParaFrenteEPararMotores() {
  Serial.println("TESTE: MOVER MOTORES PARA FRENTE E PARAR MOTORES\n");
  moverMotoresDCParaFrente();
  delay(5000);
  pararMotoresDC();
  delay(2000);
}

void testeMoverMotoresParaTrasEPararMotores() {
  Serial.println("TESTE: MOVER MOTORES PARA TRÁS E PARAR MOTORES\n");
  moverMotoresDCParaTras();
  delay(5000);
  pararMotoresDC();
  delay(2000);
}
//

void loop() {
  testeMoverMotorDireitaParaFrenteEPararMotor();
  testeMoverMotorEsquerdaParaFrenteEPararMotor();
  testeMoverMotoresParaFrenteEPararMotores();
  testeMoverMotoresParaTrasEPararMotores();
}
