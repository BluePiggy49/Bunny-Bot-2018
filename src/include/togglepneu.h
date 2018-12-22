//By JP Li

#ifndef TOGGLEPNEU_H
#define TOGGLEPNEU_H

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <iostream>

class TogglePneu {
public:
TogglePneu (
	Joystick *joystick, Solenoid *hopper_toggle)
	: joystick(joystick), hopper_toggle(hopper_toggle) {};
    bool toggle_state = 0;
    bool pneustate = 0;
    bool state_from_button = 0;
	
	void run_toggle_p (int i_button);

private: 
	Joystick *joystick;
	Solenoid *hopper_toggle;



};
#endif