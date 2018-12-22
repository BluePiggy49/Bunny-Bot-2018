//By Colton

#include <prematch.h>
void PrematchPrep::run_prematch(){
//tje c								
					 
bool on_variable = SmartDashboard::GetBoolean("DB/Button 3",false);
						//     button number,f_speed on(betwen o and 1,percent output) , speed off.
					  // run_toggle_m(1,       0.3,                                              0)
if(on_variable==1){
	drive_toggle_left_enc->   run_toggle_m(1, 0.3, 0);
//                        in this case 1 is the button, o,3 is the spped, and o is the off speed
	drive_toggle_right_enc->  run_toggle_m(2, 0.3, 0);
//run_toggle_m is the function that sets a motor to toggle on or off
	drive_toggle_left_noenc-> run_toggle_m(3,0.3, 0);
	drive_toggle_right_noenc->run_toggle_m(4, 0.3, 0);
	intake_toggle_noenc->     run_toggle_m(5, 0.3, 0);
	flipper_toggle_enc->      run_toggle_m(6, 0.3, 0);

	if (joystick->GetRawButton(7))
	{
		hopper_zero->Set(1);
		hopper_one->Set(0);
	}
		else{
			hopper_zero->Set(0);
			hopper_one->Set(1);
	}
//	define the variables for amps,voltage,position,velocity
//	the code can be shortened by changing ertain lines 
	if( drive_toggle_right_enc->is_toggle_on()==1){
//get amps, voltage,position and velocity on encoder 
		double drive_talon_right_enc_current=   drive_talon_right_enc->GetOutputCurrent();
		double drive_talon_right_voltage    =   drive_talon_right_enc->GetMotorOutputVoltage();
		int drive_talon_right_enc_velocity  =   drive_talon_right_enc->GetSelectedSensorVelocity(0);
		int drive_talon_right_enc_position  =   drive_talon_right_enc-> GetSelectedSensorPosition(0);
		std::cout<<"Amps for drive_talon_right_enc "<<""<<drive_talon_right_enc_current<<std::endl;
		std::cout<<"Voltage for drive_talon_right_enc "<<""<<drive_talon_right_voltage<<std::endl;
		std::cout<<"Position for drive_talon_right_enc "<<""<<drive_talon_right_enc_velocity<<std::endl;
		std::cout<<"Velocity for drive_talon_right_enc "<<""<<drive_talon_right_enc_position<<std::endl;

}

	if(drive_toggle_left_enc->is_toggle_on()==1){
//get amps, voltage, position, veloc
		double drive_talon_left_enc_current =   drive_talon_left_enc->GetOutputCurrent();
		double drive_talon_left_voltage    =   drive_talon_left_enc->GetMotorOutputVoltage();
		int drive_talon_left_enc_velocity  = drive_talon_left_enc->GetSelectedSensorVelocity(0);
		int drive_talon_left_enc_position  =   drive_talon_left_enc-> GetSelectedSensorPosition(0);
		std::cout<<"Amps for drive talon left enc: "<<""<<drive_talon_left_enc_current<<std::endl;
		std::cout<<"Voltage for drive talon left enc: "<<""<<drive_talon_left_voltage<<std::endl;
		std::cout<<"Position for drive talon left enc: "<<""<<drive_talon_left_enc_velocity<<std::endl;
		std::cout<<"Velocity for drive_talon  left enc:"<<""<<drive_talon_left_enc_position<<std::endl;
}
	if(drive_toggle_left_noenc->is_toggle_on()==1){
//get amps, voltage
		double drive_talon_left_noenc_current= drive_talon_left_noenc->GetOutputCurrent();
		double drive_talon_left_noenc_voltage=  drive_talon_left_noenc->GetMotorOutputVoltage();
		std::cout<<"Amps for drive_talon_left_noenc: "<<""<<drive_talon_left_noenc_current<<std::endl;
		std::cout<<"Voltage for drive_talon_left_noenc: "<<""<<drive_talon_left_noenc_voltage<<std::endl;
}

	if(drive_toggle_right_noenc->is_toggle_on()==1){
		double drive_talon_right_noenc_current= drive_talon_right_noenc->GetOutputCurrent();
		double drive_talon_right_noenc_voltage    = drive_talon_right_noenc->GetMotorOutputVoltage();
		std::cout<<"Amps for drive talon right noencn is: "<<""<<drive_talon_right_noenc_current<<std::endl;
		std::cout<<"Voltage for drive talon right noenc:  "<<""<<drive_talon_right_noenc_current<<std::endl;
//get amps, voltage
}
	if(intake_toggle_noenc->is_toggle_on()==1){
		double drive_talon_left_enc_current= intake_talon_noenc->GetOutputCurrent();
		double drive_talon_left_voltage    = intake_talon_noenc->GetMotorOutputVoltage();
//get amps, voltage
		std::cout<<"Amps for intake_talon_noenc"<<""<<intake_talon_noenc<<std::endl;
		std::cout<<"Voltage for intake_talon_noenc"<<""<<intake_talon_noenc<<std::endl;
}

	if(flipper_toggle_enc->is_toggle_on()==1){
		std::cout<<"Amps for flippper talon nooenc: "<< flipper_talon_noenc->GetOutputCurrent()<<std::endl;
		std::cout<<"Voltage for intake talon noenc: "<< flipper_talon_noenc->GetMotorOutputVoltage()<<std::endl;
}

}//this is the end parenthesis for the first if statement 
}//end of void