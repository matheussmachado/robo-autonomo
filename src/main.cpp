#include <Arduino.h>
#include "operacoes.h"


// OPERAÇÕES/FUNÇÕES INTERMEDIÁRIAS
//============================================================
bool verificarObstaculoFrontal() {
  if (medirDistanciaCm() >= DISTANCIA_FRONTAL_MINIMA) {
    return false;
  }
  return true;
}

float medirDistanciaLateral(int lado) {
  posicionarEixoDoServo(lado);
  delay(1000);
  posicionarEixoDoServo(LADO_FRONTAL); //retornar a posição inicial do sensor ultrassônico
  return medirDistanciaCm();
}

int escolherLado() {
  int ladoParaSeguir = LADO_TRASEIRO;
  int medicao, medicaoDireita, medicaoEsquerda;
  medicao = medicaoDireita = medicaoEsquerda = 0;
  medicaoDireita = medirDistanciaLateral(LADO_DIREITO);
  medicaoEsquerda = medirDistanciaLateral(LADO_ESQUERDO);
  medicao = min(medicaoDireita, medicaoEsquerda); //pois deverá haver um valor mínimo nos dois lados do robô para realizar a manobra, devido a dimensão atual do chassi.
  if (medicao >= DISTANCIA_LATERAL_MINIMA) {
    if (medicao == medicaoDireita) {
      ladoParaSeguir = LADO_ESQUERDO; //pois será o maior lado a ser seguido
    }
    else {
      ladoParaSeguir = LADO_DIREITO;
    }
  }
  delay(500);
  return ladoParaSeguir;
}

bool obstaculo;
bool manobrar;
int ladoParaSeguir;
//============================================================

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);
  setupMotoresDC();
  setupSensorUltrassonico();
  setupServoMotor();
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
      if (ladoParaSeguir == LADO_DIREITO) {
        manobrarLateral(LADO_DIREITO);
      }
      else {
        manobrarLateral(LADO_ESQUERDO);
      }
      delay(TEMPO_MANOBRA);
      manobrar = false;
    }
    else {
      locomover(SENTIDO_TRASEIRO);
      delay(TEMPO_MOVIMENTO_TRASEIRO);
      frear();
    }
  }
}
