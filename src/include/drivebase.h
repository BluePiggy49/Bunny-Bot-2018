//JP Li

#ifndef DRIVEBASE_H
#define DRIVEBASE_H

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <iostream>

class Drivebase {
public:
	Drivebase (
		Joystick *joystick, TalonSRX *drive_talon_right_enc, TalonSRX *drive_talon_left_enc)
	:
	joystick(joystick), drive_talon_right_enc(drive_talon_right_enc), drive_talon_left_enc(drive_talon_left_enc)  {};

	void run_drive (float f_max_speed, int i_joystick_x_axis, int i_joystick_x_flip, int i_joystick_y_axis, int i_joystick_y_flip);
		
private:
	Joystick *joystick;
	TalonSRX *drive_talon_right_enc;
	TalonSRX *drive_talon_left_enc;



};
#endif