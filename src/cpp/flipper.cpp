//By JP Li

#include <flipper.h>

void Flipper::run_flipper (int i_a_up_pos, int i_b_down_pos, int i_x_pos, int i_y_pos, bool b_safety,bool up_running, bool down_running, bool toggle) {
if (toggle == 0){
toggle =1;
b_safety =0;
	up_running = 0;
	down_running = 0;

}

if (flipper_talon_enc->GetMotorOutputPercent() == 0) {
	b_safety =0;
	up_running = 0;
	down_running = 0;
}
if (joystick->GetRawButton(1)==1 and b_safety == 0 and up_running == 0 and down_running == 0) {
b_safety = 1;
up_running = 1;
flipper_talon_enc -> Set(ControlMode::Position, i_a_up_pos);
std::cout<<"Flipper going up"<<std::endl;

}

if (joystick -> GetRawButton (2)==1 and b_safety == 0 and up_running == 0 and down_running == 0){
	b_safety = 1;
	down_running = 1;
	flipper_talon_enc -> Set(ControlMode::Position, i_b_down_pos);
	std::cout<<"Flipper going down"<<std::endl;

}
std::cout<<"Current Motor Pos="<<flipper_talon_enc->GetSelectedSensorPosition(0)<<std::endl;

}