//By JP Li

#include <drivebase.h>

void Drivebase::run_drive (float f_max_speed, int i_joystick_x_axis, int i_joystick_x_flip, int i_joystick_y_axis, int i_joystick_y_flip){
  
drive_talon_right_enc->Set(ControlMode::PercentOutput,
//Config Max Speed
	f_max_speed 
	*
	(
		//Get Correct Value
		(joystick->GetRawAxis(i_joystick_x_axis)*i_joystick_x_flip)
		-
		(joystick->GetRawAxis(i_joystick_y_axis)*i_joystick_y_flip)
		

	)





 );
drive_talon_left_enc->Set(ControlMode::PercentOutput,

f_max_speed
*
(
(joystick->GetRawAxis(i_joystick_y_axis)*i_joystick_y_flip)
+
(joystick->GetRawAxis(i_joystick_x_axis)*i_joystick_x_flip)

	)





	);

}