#include <Arduino.h>
#include "operacoes.h"

void setupSensorUltrassonico() {
  pinMode(PIN_SENSOR_ULTRASSONIC_TRIGGER, OUTPUT);
  pinMode(PIN_SENSOR_ULTRASSONIC_ECHO, INPUT);
  digitalWrite(PIN_SENSOR_ULTRASSONIC_TRIGGER, LOW);
}

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
