//By JP Li

#include <togglepneu.h>

void TogglePneu::run_toggle_p (int i_button){

	bool button_state = joystick->GetRawButton(i_button);

    if (button_state == 1 and pneustate == 0 and toggle_state == 0){
    	hopper_toggle->Set(1 - hopper_toggle->Get());	
    	pneustate = 1 ;

    
   	}
    if (button_state == 0 and pneustate == 1) {
    	toggle_state = toggle_state + 1;
    }
    if (button_state == 1 and pneustate == 1 and toggle_state == 1) {
    	hopper_toggle->Set(1 - hopper_toggle->Get());
    	pneustate = 0 ;
    	toggle_state = 0;
	}
}