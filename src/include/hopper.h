#ifndef HOPPER_H
#define HOPPER_H

#include <WPILib.h>
#include <ctre/Phoenix.h>
#include <iostream>
#include <Joystick.h>
#include <cmath>
#include <togglepneu.h>

class Hopper{
	public:
		Hopper(TogglePneu *hoppertoggle, Solenoid *hopper, Solenoid *hopper_two, Joystick *joystick) 
		: hoppertoggle(hoppertoggle),  hopper(hopper), hopper_two(hopper_two), joystick(joystick){};
		
		void run_hopper();

	private:
		TogglePneu *hoppertoggle;
		Solenoid *hopper, *hopper_two;
		Joystick *joystick;
};
#endif