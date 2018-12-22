//By Kevin Chang

#ifndef TOGGLEMOTOR_H

#define TOGGLEMOTOR_H


#include <iostream>
#include <WPILib.h>
#include <ctre/Phoenix.h>
#include <iostream>
#include <cmath>

using namespace frc;

    
class ToggleMotor {

    public:
        ToggleMotor(
    Joystick *joystick,   
    TalonSRX *toggle_talon)
    
    : joystick(joystick),
    toggle_talon(toggle_talon) {}; 

    void run_toggle_m(int i_button, float f_speed_on, float f_speed_off); 
    bool is_toggle_on();
private:

        Joystick* joystick;

        TalonSRX* toggle_talon;
    bool b_state_from_button;
    bool b_toggle_state = 0;
    bool b_button_state = 0;

};

#endif