// This library created to compatible with Canon Expansion Board for Canon chietech 2021.
// Using Arduino mega 2560.

#ifndef _DCMotor_h_
#define _DCMotor_h_

#if ARDUINO > 22
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

// PWM control speed of motor
#define M1_PWM  9
#define M2_PWM  11
#define M3_PWM  10
#define M4_PWM  12

// IO control dirrection of motor 
#define M1_IO1  50
#define M1_IO2  51
#define M2_IO1  46
#define M2_IO2  47
#define M3_IO1  50
#define M3_IO2  49
#define M4_IO1  45
#define M4_IO2  44

#define LIFT_UP     1
#define LIFT_DOWN   -1
#define LIFT_STOP   0



class DCMotor
{
private:
    /* data */
public:
    void Init();
    void Run(int motor_number, int pwm, bool dir);
    void Stop(int motor_number);
    void Lift(int status, int pwm); //up, down or stop

};


#endif 