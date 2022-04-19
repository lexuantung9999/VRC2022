#include <Arduino.h>
#include <DCMotor.h>
#include <main.h>

DCMotor VRC_DCMotor;
char command;
int cmd_vel = BASE_VEL;
unsigned long time;

void setup() {
  // put your setup code here, to run once:
  VRC_DCMotor.Init();
  Serial1.begin(115200);
  Serial.begin(115200);
  pinMode(END_STOP_LIFT_DOWN, INPUT_PULLUP)
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial1.available()){
    command = Serial1.read();
    Serial.println(command);
    switch(command){
      case RY_H:
        VRC_DCMotor.Run(2,cmd_vel,1);
        VRC_DCMotor.Run(4,cmd_vel,1);
        break;
      case RY_L:
        VRC_DCMotor.Run(2,cmd_vel,0);
        VRC_DCMotor.Run(4,cmd_vel,0);
        break;
      case RX_H:
        VRC_DCMotor.Run(2,cmd_vel,1);
        VRC_DCMotor.Run(4,cmd_vel,0);
        break;
      case RX_L:
        VRC_DCMotor.Run(2,cmd_vel,0);
        VRC_DCMotor.Run(4,cmd_vel,1);
        break;
      case PS2_Up:
        cmd_vel +=10;
        break;
      case PS2_Down:
        cmd_vel -=10;
        break;
      case PS2_L3:
        cmd_vel = BASE_VEL;
        break;
    }
    time = millis();
  }
  
  if(millis() - time > CMD_TIME_OUT){
        VRC_DCMotor.Stop(2);
        VRC_DCMotor.Stop(4);
  }

}