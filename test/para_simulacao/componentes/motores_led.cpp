#include <Arduino.h> //NÃO USAR ESSA LINHA SE ESTIVER USANDO O ARDUINO IDE OU ALGUM SIMULADOR ONLINE

/*
PROPÓSITO: EMULAR O COMPORTAMENTO DE UM MOTOR DC UTILIZANDO LEDS. EM ÚLTIMA INSTÂNCIA, SERÃO UTILIZADAS AS FUNÇÕES PARA CONTROLAR O MOVIMENTO FINAL DE UM MOTOR DC. PORTANTO, O NOME DC EM FUNÇÕES SERVIRÃO PARA TESTAR O MOVIMENTO DE UM MOTOR AO RECEBER O FEEDBACK DO SENSOR DE DISTÂNCIA
*/
/*
#define PIN_MOTOR_LED_ESQUERDA_FRONTAL 4
#define PIN_MOTOR_LED_ESQUERDA_MEIO 3
#define PIN_MOTOR_LED_ESQUERDA_TRASEIRO 2
#define PIN_MOTOR_LED_DIREITA_FRONTAL 11
#define PIN_MOTOR_LED_DIREITA_MEIO 12
#define PIN_MOTOR_LED_DIREITA_TRASEIRO 13


//INICIO MOTORES LED **********************************************
#define SENTIDO_FRONTAL 1
#define SENTIDO_TRASEIRO 0


struct MotorLED {
  unsigned int frontal;
  unsigned int meio;
  unsigned int traseiro;  
};

// MOTOR LED UNITÁRIO

void iniciarMotorDC(struct MotorLED &motor, int pin_frontal, int pin_meio,int pin_traseiro) {
  motor.frontal = pin_frontal;
  motor.meio = pin_meio;
  motor.traseiro = pin_traseiro;
}

void reiniciaMotor(struct MotorLED motor) {
  digitalWrite(motor.frontal, LOW);
  digitalWrite(motor.meio, LOW);
  digitalWrite(motor.traseiro, LOW);
}

//

struct MotorLED motorEsquerda;
struct MotorLED motorDireita;

void setupMotoresDC() {
  pinMode(PIN_MOTOR_LED_ESQUERDA_FRONTAL, OUTPUT);
  pinMode(PIN_MOTOR_LED_ESQUERDA_MEIO, OUTPUT);
  pinMode(PIN_MOTOR_LED_ESQUERDA_TRASEIRO, OUTPUT);
  pinMode(PIN_MOTOR_LED_DIREITA_FRONTAL, OUTPUT);
  pinMode(PIN_MOTOR_LED_DIREITA_MEIO, OUTPUT);
  pinMode(PIN_MOTOR_LED_DIREITA_TRASEIRO, OUTPUT);
  iniciarMotorDC(motorEsquerda, PIN_MOTOR_LED_ESQUERDA_FRONTAL, PIN_MOTOR_LED_ESQUERDA_MEIO, PIN_MOTOR_LED_ESQUERDA_TRASEIRO);
  iniciarMotorDC(motorDireita, PIN_MOTOR_LED_DIREITA_FRONTAL, PIN_MOTOR_LED_DIREITA_MEIO, PIN_MOTOR_LED_DIREITA_TRASEIRO);
}



void reiniciaMotores() {
  reiniciaMotor(motorEsquerda);
  reiniciaMotor(motorDireita);
}

void locomover(int sentido) {
  reiniciaMotores();
  if (sentido == SENTIDO_FRONTAL) {
    digitalWrite(motorEsquerda.frontal, HIGH);
    digitalWrite(motorDireita.frontal, HIGH);
  }
  else {
    digitalWrite(motorEsquerda.traseiro, HIGH);
    digitalWrite(motorDireita.traseiro, HIGH);
  }
}

void frear() {
  reiniciaMotores();
  digitalWrite(motorEsquerda.meio, HIGH);
  digitalWrite(motorDireita.meio, HIGH);
}

void manobrarDireita() {
  reiniciaMotores();
  digitalWrite(motorEsquerda.frontal, HIGH);
  digitalWrite(motorDireita.traseiro, HIGH);
}

void manobrarEsquerda() {
  reiniciaMotores();
  digitalWrite(motorEsquerda.traseiro, HIGH);
  digitalWrite(motorDireita.frontal, HIGH);
}

//FIM MOTORES LED **********************************************


//TESTES DE VISTA

void testeMoverMotoresParaFrenteEPararMotores() {
  Serial.println("TESTE: MOVER MOTORES PARA FRENTE E PARAR MOTORES\n");
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

void testeManobrarParaDireitaEPararMotores() {
  Serial.println("TESTE: MANOBRAR PARA A DIREITA E PARAR MOTORES\n");
  manobrarDireita();
  delay(5000);
  frear();
  delay(2000);
}

void testeManobrarParaEsquerdaEPararMotores() {
  Serial.println("TESTE: MANOBRAR PARA A ESQUERDA E PARAR MOTORES\n");
  manobrarEsquerda();
  delay(5000);
  frear();
  delay(2000);
}

//

//FIM MOTORES LED *********************************************************

void setup() {
  Serial.begin(9000);
  setupMotoresDC();
}

void loop() {
  testeMoverMotoresParaFrenteEPararMotores();
  testeMoverMotoresParaTrasEPararMotores();
  testeManobrarParaDireitaEPararMotores();
  testeManobrarParaEsquerdaEPararMotores();
}
*/