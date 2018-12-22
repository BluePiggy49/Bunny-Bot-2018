#ifndef PRESS_AND_HOLD_H
#define PRESS_AND_HOLD_H

#include <WPILib.h>
#include <ctre/Phoenix.h>
#include <iostream>
#include <Joystick.h>
#include <cmath>

class PressAndHold{
	public:
		PressAndHold(Joystick* joystick, TalonSRX* holdtalon) : joystick(joystick), holdtalon(holdtalon) {};
		void hold(int button, float speed_on, float speed_off);

	private:
		Joystick *joystick;
		TalonSRX *holdtalon;
		bool button_state = 0;
};
#endif