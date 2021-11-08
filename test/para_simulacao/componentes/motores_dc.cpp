/*
#include <Arduino.h> //NÃO USAR ESSA LINHA SE ESTIVER USANDO O ARDUINO IDE OU ALGUM SIMULADOR ONLINE
// como permitir que as instancias dos motores sejam usadas em escopos distintos

#define PIN_MOTOR_DC_ESQUERDA_POSITIVO 7
#define PIN_MOTOR_DC_ESQUERDA_NEGATIVO 8
#define PIN_MOTOR_DC_ESQUERDA_ENABLE 5
#define PIN_MOTOR_DC_DIREITA_POSITIVO 2
#define PIN_MOTOR_DC_DIREITA_NEGATIVO 4
#define PIN_MOTOR_DC_DIREITA_ENABLE 3

#define SENTIDO_FRONTAL HIGH
#define SENTIDO_TRASEIRO LOW
#define VEL_PADRAO 200
#define VEL_MOTOR_ESQUERDA_OPCIONAL 200
#define VEL_MOTOR_DIREITA_OPCIONAL 130


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

struct MotorDC motorEsquerda;
struct MotorDC motorDireita;

void setupMotoresDC() {
  pinMode(PIN_MOTOR_DC_ESQUERDA_POSITIVO, OUTPUT);
  pinMode(PIN_MOTOR_DC_ESQUERDA_NEGATIVO, OUTPUT);
  pinMode(PIN_MOTOR_DC_DIREITA_POSITIVO, OUTPUT);
  pinMode(PIN_MOTOR_DC_DIREITA_NEGATIVO, OUTPUT);
  iniciarMotorDC(motorDireita, PIN_MOTOR_DC_DIREITA_POSITIVO, PIN_MOTOR_DC_DIREITA_NEGATIVO, PIN_MOTOR_DC_DIREITA_ENABLE);
  iniciarMotorDC(motorEsquerda, PIN_MOTOR_DC_ESQUERDA_POSITIVO, PIN_MOTOR_DC_ESQUERDA_NEGATIVO, PIN_MOTOR_DC_ESQUERDA_ENABLE);  
}

void locomover(int sentido) {
  moverMotorDC(motorEsquerda, sentido);
  moverMotorDC(motorDireita, sentido);
}

void frear() {
  pararMotorDC(motorEsquerda);
  pararMotorDC(motorDireita);
}

void manobrarEsquerda() {
  moverMotorDC(motorEsquerda, SENTIDO_TRASEIRO);
  moverMotorDC(motorDireita, SENTIDO_FRONTAL);
}

void manobrarDireita() {
  moverMotorDC(motorEsquerda, SENTIDO_FRONTAL);
  moverMotorDC(motorDireita, SENTIDO_TRASEIRO);
}

//

//TESTES DE VISTA

void testeMoverMotorDireitaParaFrenteEPararMotor() {
  Serial.println("TESTE: MOVER MOTOR DA DIREITA PARA FRENTE E PARAR MOTOR\n");
  moverMotorDC(motorDireita, SENTIDO_FRONTAL);
  delay(5000);
  frear();
  delay(2000);
}

void testeMoverMotorEsquerdaParaFrenteEPararMotor() {
  Serial.println("TESTE: MOVER MOTOR DA ESQUERDA PARA FRENTE E PARAR MOTOR\n");
  moverMotorDC(motorEsquerda, SENTIDO_FRONTAL);
  delay(5000);
  frear();
  delay(2000);
}

void testeMoverMotoresParaFrenteEPararMotores() {
  Serial.println("TESTE: MOVER MOTORES PARA FRENTE E PARAR MOTORES\n");
  //locomoverParaFrente();
  locomover(SENTIDO_FRONTAL);
  delay(5000);
  frear();
  delay(2000);
}

void testeMoverMotoresParaTrasEPararMotores() {
  Serial.println("TESTE: MOVER MOTORES PARA TRÁS E PARAR MOTORES\n");
  locomover(SENTIDO_TRASEIRO);
  delay(5000);
  frear();
  delay(2000);
}

void testeManobrarDireita() {
  Serial.println("TESTE: MANOBRAR À DIREITA\n");
  manobrarDireita();
  delay(5000);
  frear();
  delay(2000);
}

void testeManobrarEsquerda() {
  Serial.println("TESTE: MANOBRAR À ESQUERDA\n");
  manobrarEsquerda();
  delay(5000);
  frear();
  delay(2000);
}
//

//FIM MOTORES DC *********************************************************

void setup() {
  Serial.begin(9000);
  setupMotoresDC();
}

void loop() {
  testeMoverMotorDireitaParaFrenteEPararMotor();
  testeMoverMotorEsquerdaParaFrenteEPararMotor();
  testeMoverMotoresParaFrenteEPararMotores();
  testeMoverMotoresParaTrasEPararMotores();
  testeManobrarDireita();
  testeManobrarEsquerda();
}
*/