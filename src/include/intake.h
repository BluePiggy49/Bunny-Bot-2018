//By Colton

#ifndef INTAKE_H
#define INTAKE_H
#include <ctre/Phoenix.h>
#include <iostream>
#include <Joystick.h>
#include "pressandhold.h"
#include <WPILib.h>
class Intake
{
 public:
 //the constructor takes the following parameters
 Intake(PressAndHold *intake_hold, TalonSRX *intake_talon,Joystick *joystick ) : intake_hold(intake_hold), intake_talon(intake_talon), joystick(joystick) {};
 
 //void  intake_hold(intake_hold){};
 //this is the function that takes the parameter f_max_speed and does
 void  run_intake(float f_max_speed);
 void intake_options(float f_max_speed);
 void intake_reverse(float f_max_speed);
 private:
  PressAndHold *intake_hold;
  TalonSRX *intake_talon;
  Joystick *joystick;//the name is important

 };
#endif