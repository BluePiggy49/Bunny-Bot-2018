//By Colton

#ifndef  PREMATACH_h
#define  PREMATACH_h

#include <WPILib.h>
#include <ctre/Phoenix.h>
#include <iostream>
#include "intake.h"
#include "togglemotor.h"

class PrematchPrep{

public:
	/*this is where the contructors go "*/
	PrematchPrep(TalonSRX *drive_talon_right_enc, ToggleMotor *drive_toggle_right_enc, 
			 TalonSRX *drive_talon_right_noenc, ToggleMotor *drive_toggle_right_noenc, 
			 
			 TalonSRX *drive_talon_left_enc, ToggleMotor *drive_toggle_left_enc,
			 TalonSRX *drive_talon_left_noenc,ToggleMotor *drive_toggle_left_noenc,
			 
			 TalonSRX *intake_talon_noenc,ToggleMotor *intake_toggle_noenc,
			 
			 TalonSRX *flipper_talon_noenc,ToggleMotor *flipper_toggle_enc,

			 Solenoid *hopper_zero, Solenoid *hopper_one, Joystick *joystick

			   )
			      :  
			    
			    drive_talon_right_enc( drive_talon_right_enc),
			   	drive_toggle_right_enc(drive_toggle_right_enc),
			   
			    drive_talon_right_noenc(drive_talon_right_noenc),
			   	drive_toggle_right_noenc(drive_toggle_right_noenc),
			   
			    drive_talon_left_enc(drive_talon_left_enc), 
			   	drive_toggle_left_enc(drive_toggle_left_enc),

			    drive_talon_left_noenc(drive_talon_left_noenc),
			    drive_toggle_left_noenc(drive_toggle_left_noenc),

			    intake_talon_noenc(intake_talon_noenc),
			    intake_toggle_noenc(intake_toggle_noenc),
			   
			    
			    flipper_talon_noenc(flipper_talon_noenc),
			    
			    flipper_toggle_enc(flipper_toggle_enc),

			    hopper_zero(hopper_zero), hopper_one(hopper_one), joystick(joystick)
	

			    {};

	 //name of my function {some of the constructors of my function}
		 void run_prematch();
		 	
private:
TalonSRX*drive_talon_right_enc; ToggleMotor*drive_toggle_right_enc; 
			 TalonSRX *drive_talon_right_noenc;

			 ToggleMotor *drive_toggle_right_noenc; 
			 
			 TalonSRX *drive_talon_left_enc; 

			 ToggleMotor *drive_toggle_left_enc;
			 
			 TalonSRX *drive_talon_left_noenc;						 
			 
			 TalonSRX *intake_talon_noenc;
			 
			 ToggleMotor *drive_toggle_left_noenc;

			 ToggleMotor *intake_toggle_noenc;
			 
			 TalonSRX *flipper_talon_noenc;    

			 ToggleMotor *flipper_toggle_enc;

			 Solenoid *hopper_zero, *hopper_one;
			 Joystick *joystick;




};

#endif