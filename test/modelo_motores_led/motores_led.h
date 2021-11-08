#ifndef MOTORES_LED
#define MOTORES_LED

struct MotorDC {
  //MODELO DE CONJUNTO DE 3 LEDS QUE EMULAM O SENTIDO DE GIRO DE UM MOTOR DC
  unsigned int frontal;
  unsigned int meio;
  unsigned int traseiro;  
};  

void iniciarMotorDC(struct MotorDC &motor, int pin_frontal, int pin_meio,int pin_traseiro);

void reiniciaMotor(struct MotorDC motor);

#endif
