#include <hopper.h>

void Hopper::run_hopper(){
	if (joystick->GetRawButton(4))
        {
            hopper->Set(1);
            hopper_two->Set(0); //closed
        }
        else{
            hopper->Set(0);
            hopper_two->Set(1); //open
        }
}