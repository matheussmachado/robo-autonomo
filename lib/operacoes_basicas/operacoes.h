#ifndef OPERACOES_H
#define OPERACOES_H

#include <Arduino.h>
#include "motores_led.h"
//#include "motores_dc.h"

// DEFINIÇÕES DE PINAGEM
//============================================================
#define PIN_MOTOR_DC_ESQUERDO_POSITIVO 7
#define PIN_MOTOR_DC_ESQUERDO_NEGATIVO 8
#define PIN_MOTOR_DC_ESQUERDO_ENABLE 5
#define PIN_MOTOR_DC_DIREITO_POSITIVO 2
#define PIN_MOTOR_DC_DIREITO_NEGATIVO 4
#define PIN_MOTOR_DC_DIREITO_ENABLE 3

#define PIN_SERVO_MOTOR 10

#define PIN_SENSOR_ULTRASSONIC_TRIGGER 12
#define PIN_SENSOR_ULTRASSONIC_ECHO 11
//============================================================


// DEFINIÇÕES GERAIS
//============================================================
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
//============================================================


// MOTORES DC 
//============================================================
extern struct MotorDC motorEsquerdo;
extern struct MotorDC motorDireito;

void locomover(int sentido);
void frear();
void manobrarLateral(int lado);
void setupMotoresDC();
//============================================================


// SENSOR ULTRASSONICO
//============================================================
float medirDistanciaCm();
void setupSensorUltrassonico();
//============================================================


// SERVO MOTOR
//============================================================
void posicionarEixoDoServo(int angulo);
void setupServoMotor();
//============================================================

#endif