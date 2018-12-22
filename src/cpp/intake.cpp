//By Colton

#include <intake.h>
void Intake::run_intake (float f_max_speed){
 intake_hold->hold(6,f_max_speed,0);
 std::cout<<"the intake part ran "<<std::endl;
 //include the amp reading from the talons
 double amp=intake_talon->GetOutputCurrent();
  
std::cout<<"this is the amp reading: "<<amp<<std::endl;
std::cout<<"this is the voltage reading"<<intake_talon->GetMotorOutputVoltage()<<std::endl;
}
void Intake::intake_options(float f_max_speed){//be sure that the input is a integar)

std::cout<<"this is the amp reading"<<intake_talon->GetOutputCurrent()<<std::endl;
std::cout<<"this is the amp reading" << intake_talon->GetMotorOutputVoltage()<<std::endl;
float hope_this_works= joystick->GetRawAxis(3);
double x_pos =	hope_this_works;
float adjusted_speed = x_pos*f_max_speed;
intake_talon->Set(ControlMode::PercentOutput,adjusted_speed);
}
void Intake::intake_reverse(float f_max_speed){
std::cout<<"this is the amp reading"<<intake_talon->GetOutputCurrent()<<std::endl;
std::cout<<"this is the amp reading" << intake_talon->GetMotorOutputVoltage()<<std::endl;
float hope_this_works= joystick->GetRawAxis(2);
double x_pos =	hope_this_works;
float adjusted_speed = -1*x_pos*f_max_speed;
intake_talon->Set(ControlMode::PercentOutput,adjusted_speed);
}