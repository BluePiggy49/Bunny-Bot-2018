//By JP Li

#ifndef FLIPPER_H
#define FLIPPER_H


#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <iostream>

class Flipper {
public:
	Flipper(
		Joystick *joystick, TalonSRX *flipper_talon_enc)
	:
	joystick(joystick), flipper_talon_enc(flipper_talon_enc) {};

	void run_flipper( int i_a_up_pos, int i_b_down_pos, int i_x_pos, int i_y_pos, bool b_safety, bool up_running, bool down_running, bool toggle); 
private:


Joystick *joystick;
TalonSRX *flipper_talon_enc;



};
#endif