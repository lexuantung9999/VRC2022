#include <DCMotor.h>


void DCMotor::Init(){
    pinMode(M1_PWM, OUTPUT); pinMode(M2_PWM, OUTPUT); pinMode(M3_PWM, OUTPUT); pinMode(M4_PWM, OUTPUT);
    pinMode(M1_IO1,OUTPUT); pinMode(M1_IO2,OUTPUT); pinMode(M2_IO1,OUTPUT); pinMode(M2_IO2,OUTPUT);
    pinMode(M3_IO1,OUTPUT); pinMode(M3_IO2,OUTPUT); pinMode(M4_IO1,OUTPUT); pinMode(M4_IO2,OUTPUT);  
}

void DCMotor::Run(int motor_number, int pwm, bool dir){
    switch(motor_number){
        case 1:
            digitalWrite(M1_IO1,bool(dir));
            digitalWrite(M1_IO2,bool(!dir));
            analogWrite(M1_PWM,pwm);
            break;
        case 2:
            digitalWrite(M2_IO1,bool(dir));
            digitalWrite(M2_IO2,bool(!dir));
            analogWrite(M2_PWM,pwm);
            break;
        case 3:
            digitalWrite(M3_IO1,bool(dir));
            digitalWrite(M3_IO2,bool(!dir));
            analogWrite(M3_PWM,pwm);
            break;
        case 4:
            digitalWrite(M4_IO1,bool(dir));
            digitalWrite(M4_IO2,bool(!dir));
            analogWrite(M4_PWM,pwm);
            break;
    }
}

void DCMotor::Stop(int motor_number){
        switch(motor_number){
        case 1:
            // digitalWrite(M1_IO1,bool(dir));
            // digitalWrite(M1_IO2,bool(!dir));
            analogWrite(M1_PWM,0);
            break;
        case 2:
            // digitalWrite(M2_IO1,bool(dir));
            // digitalWrite(M2_IO2,bool(!dir));
            analogWrite(M2_PWM,0);
            break;
        case 3:
            // digitalWrite(M3_IO1,bool(dir));
            // digitalWrite(M3_IO2,bool(!dir));
            analogWrite(M3_PWM,0);
            break;
        case 4:
            // digitalWrite(M4_IO1,bool(dir));
            // digitalWrite(M4_IO2,bool(!dir));
            analogWrite(M4_PWM,0);
            break;
    }
}


void DCMotor::Lift(int status, int pwm){
    // fix lift_motor in Motor 3
    DCMotor lift_motor;
    switch (status)
    {
    case (LIFT_UP):
        /* code */
        lift_motor.Run(3,pwm,1);
        break;
    
    case (LIFT_DOWN):
        lift_motor.Run(3,pwm,0);
        break;

    case (LIFT_STOP):
        lift_motor.Stop(3);
        break;    
    }
}