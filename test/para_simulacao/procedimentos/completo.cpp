#define PIN_MOTOR_DC_ESQUERDO_POSITIVO 7
#define PIN_MOTOR_DC_ESQUERDO_NEGATIVO 8
#define PIN_MOTOR_DC_ESQUERDO_ENABLE 5
#define PIN_MOTOR_DC_DIREITO_POSITIVO 2
#define PIN_MOTOR_DC_DIREITO_NEGATIVO 4
#define PIN_MOTOR_DC_DIREITO_ENABLE 3
#define PIN_SERVO_MOTOR 10
#define PIN_SENSOR_ULTRASSONIC_TRIGGER 12
#define PIN_SENSOR_ULTRASSONIC_ECHO 11

#define SENTIDO_FRONTAL HIGH
#define SENTIDO_TRASEIRO LOW
#define LADO_ESQUERDO 180 //SENTIDO OESTE DO ROBÔ
#define LADO_FRONTAL 90 //SENTIDO NORTE DO ROBÔ
#define LADO_DIREITO 0 // SENTIDO LESTE DO ROBÔ
#define LADO_TRASEIRO -90// SENTIDO SUL DO ROBÔ
#define DISTANCIA_FRONTAL_MINIMA 5 // CENTÍMETROS
#define DISTANCIA_LATERAL_MINIMA 15// CENTÍMETROS
#define TEMPO_MANOBRA 2000 // MILISSEGUNDOS
#define TEMPO_MOVIMENTO_TRASEIRO 2000 // MILISSEGUNDOS
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
  distanciaCm = duracaoPulsoEcho/58; //58 é o valor informado pelo fabricante, para a conversão em centímetro do da duração do pulso
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
  delay(500);
}

void manobrarLateral(int lado) {
  if (lado == LADO_DIREITO) {
    moverMotorDC(motorEsquerdo, SENTIDO_FRONTAL);
    moverMotorDC(motorDireito, SENTIDO_TRASEIRO);
  }
  else {
    moverMotorDC(motorEsquerdo, SENTIDO_TRASEIRO);
    moverMotorDC(motorDireito, SENTIDO_FRONTAL);
  }
}

//

// FIM MOTORES DC *********************************************************

// INÍCIO SERVO MOTOR *********************************************************
#include <Servo.h>

Servo servo;

void setupServoMotor() {
  servo.attach(PIN_SERVO_MOTOR);
  servo.write(LADO_FRONTAL);
  delay(500);
}

void posicionarEixoDoServo(int angulo) {
  //FUNÇÃO QUE SERVIRÁ PARA GIRAR O SENSOR ULTRASSÔNICO PARA UM LADO ESPECÍFICO
  servo.write(angulo);
}

// FIM SERVO MOTOR *********************************************************

bool verificarObstaculoFrontal() {
  if (medirDistanciaCm() >= DISTANCIA_FRONTAL_MINIMA) {
    return false;
  }
  return true;
}

float medirDistanciaLateral(int lado) {
  posicionarEixoDoServo(lado);
  delay(2000);
  posicionarEixoDoServo(LADO_FRONTAL); //retornar a posição inicial do sensor ultrassônico
  return medirDistanciaCm();
}

int escolherLado() {
  int ladoParaSeguir = LADO_TRASEIRO;
  int medicao, medicaoDireita, medicaoEsquerda;
  medicao = medicaoDireita = medicaoEsquerda = 0;
  medicaoDireita = medirDistanciaLateral(LADO_DIREITO);
  medicaoEsquerda = medirDistanciaLateral(LADO_ESQUERDO);
  medicao = max(medicaoDireita, medicaoEsquerda); //obter o máximo entre as medições
  if (medicao >= DISTANCIA_LATERAL_MINIMA) {
    if (medicao == medicaoDireita) {
      ladoParaSeguir = LADO_DIREITO;
    }
    else {
      ladoParaSeguir = LADO_ESQUERDO;
    }
  }
  delay(1000);
  return ladoParaSeguir;
}

bool obstaculo;
bool manobrar;
int ladoParaSeguir;

void setup() {
  setupMotoresDC();
  setupSensorUltrassonico();
  setupServoMotor();
  delay(2000);
}

void loop() {
  obstaculo = verificarObstaculoFrontal();  
  if (obstaculo == false) {
      locomover(SENTIDO_FRONTAL);
      return;
  }
  frear();
  manobrar = true;
  while (manobrar) {
    ladoParaSeguir = escolherLado();
    if (ladoParaSeguir != LADO_TRASEIRO) {
      manobrar = false;
      if (ladoParaSeguir == LADO_DIREITO) {
        manobrarLateral(LADO_DIREITO);
      }
      else {
        manobrarLateral(LADO_ESQUERDO);
      }
      delay(TEMPO_MANOBRA);
    }
    else {
      locomover(SENTIDO_TRASEIRO);
      delay(TEMPO_MOVIMENTO_TRASEIRO);
      frear();
    }
  }
}
