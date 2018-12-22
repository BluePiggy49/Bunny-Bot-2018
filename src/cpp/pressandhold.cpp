#include <pressandhold.h>

void PressAndHold::hold(int button, float speed_on, float speed_off){
	button_state = joystick->GetRawButton(button);
	if (button_state == 1)
	{
		holdtalon->Set(ControlMode::PercentOutput, speed_on);
	}
	if (button_state == 0)
	{
		holdtalon->Set(ControlMode::PercentOutput, speed_off);
	}
}
