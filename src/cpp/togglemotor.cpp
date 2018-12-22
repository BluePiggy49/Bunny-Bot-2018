//By Kevin Chang

#include <togglemotor.h>

void ToggleMotor::run_toggle_m(int i_button, float f_speed_on, float f_speed_off){ 
			
			bool b_state_from_button = joystick -> GetRawButton(i_button);

            if (b_state_from_button == 1 and b_toggle_state == 0 and b_button_state == 0)
        {
            b_toggle_state = 1;
            toggle_talon -> Set(ControlMode::PercentOutput, (f_speed_on));         
            b_button_state = 1;
         }
          if (b_state_from_button == 1 and b_toggle_state == 1 and b_button_state == 0)
           {
            b_toggle_state = 0;
            toggle_talon -> Set(ControlMode::PercentOutput, (f_speed_off));   
            b_button_state = 1;
   
           }  

            if (b_state_from_button == 0) 
            {
                b_button_state = 0;
            }  
        
        
}

bool ToggleMotor::is_toggle_on(){
  if (b_toggle_state == 1) {
    return 1;
  }
  if (b_toggle_state == 0) {
    return 0;
  }
}