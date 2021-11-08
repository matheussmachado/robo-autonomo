#ifndef MOTORES_DC
#define MOTORES_DC

#include <Arduino.h>

#define VEL_PADRAO 200

struct MotorDC {
  unsigned int positivo;
  unsigned int negativo;
  unsigned int enable;
  unsigned int velocidade;
};

void iniciarMotorDC(struct MotorDC &motor, int pin_positivo, int pin_negativo, int pin_enable, int vel=VEL_PADRAO);

void moverMotorDC(struct MotorDC motor, int sentido);

void pararMotorDC(struct MotorDC motor);

#endif
