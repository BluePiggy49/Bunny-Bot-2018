//By Erica Wood

#include <auto.h>

void Auto::run_auto(){
	if (mode == 1){
		timer->Start();
		wipe();
	}
	if (mode == 2){
		straight(7);
		intake->Set(ControlMode::PercentOutput, 0.25);
	}
	if (mode == 3){
		wipe();
	}
	if (mode == 4){
		turn(1, 90);
		intake->Set(ControlMode::PercentOutput, 0);
	}
	if (mode == 5){
		wipe();
	}
	if (mode == 6){
		straight(-5);
		intake->Set(ControlMode::PercentOutput, 0);
	}
	if (mode == 7){
		intake->Set(ControlMode::PercentOutput, 0);
		talon_left->Set(ControlMode::PercentOutput, 0);
		talon_right->Set(ControlMode::PercentOutput, 0);
		if (timer->Get() - timey >= 2)
		{
			hopper_zero->Set(1);
			hopper_one->Set(0);
		}
		std::cout<<"Not yet in timer->Get() if statement"<<std::endl;		
		if (timer->Get() - timey >= 4){
			std::cout<<"Inside timer->Get() if statement"<<std::endl;
			hopper_zero->Set(0);
			hopper_one->Set(1);
			wipe();
			std::cout<<"Just finished wiping it"<<std::endl;
		}
	}
	if (mode == 8){
		std::cout<<"We are now ready to continue moving"<<std::endl;
		straight(3);
		intake->Set(ControlMode::PercentOutput, 0.25);
	}
	if (mode == 9){
		wipe();
	}
	if (mode == 10){
		turn_counter();
		intake->Set(ControlMode::PercentOutput, 0);
	}
	if (mode == 11){
		wipe();
	}
	/*if (mode == 12){
		straight(7);
	}
	if (mode == 13){
		wipe();
	}
	if (mode == 14){
		turn(1, 90);
	}
	if (mode == 15){
		wipe();
	}
	if (mode == 16){
		straight(-5);
	}
	if (mode == 17){
		talon_left->Set(ControlMode::PercentOutput, 0);
		talon_right->Set(ControlMode::PercentOutput, 0);
		
		if (timer->Get() - timey >= 1){
			std::cout<<"Huh?"<<std::endl;
			wipe();
		}
	}
	if (mode == 19){
		straight(5);
	}
	if (mode == 20){
		wipe();
	}
	if (mode == 21){
		turn_counter();
	}
	if (mode == 22){
		straight(7);
	}
	if (mode == 23){
		wipe();
	}
	if (mode == 24){
		turn(1, 90);
	}
	if (mode == 25){
		wipe();
	}
	if (mode == 26){
		straight(-5);
	}
	if (mode == 27){
		talon_left->Set(ControlMode::PercentOutput, 0);
		talon_right->Set(ControlMode::PercentOutput, 0);
		
		if (timer->Get() - timey >= 1){
			std::cout<<"Huh?"<<std::endl;
			wipe();
		}
	}
	if (mode == 28){
		straight(5);
	}*/
	if (mode == 12){
		talon_left->Set(ControlMode::PercentOutput, 0);
		talon_right->Set(ControlMode::PercentOutput, 0);
	}
	std::cout<<"i_total_encoder_counts: "<<i_total_encoder_counts<<std::endl;
	std::cout<<"talon_left->GetSelectedSensorPosition(): "<<talon_left->GetSelectedSensorPosition(0)<<std::endl;
	std::cout<<"talon_right->GetSelectedSensorPosition(): "<<talon_right->GetSelectedSensorPosition(0)<<std::endl;
	std::cout<<std::endl;
}
void Auto::basic_auto(){
	if (mode == 1){
		timer->Start();
		wipe();
	}
	if (mode == 2){
		straight(-1);
	}
	if (mode == 3){
		wipe();
	}
	if (mode == 4){
		intake->Set(ControlMode::PercentOutput, 0);
		talon_left->Set(ControlMode::PercentOutput, 0);
		talon_right->Set(ControlMode::PercentOutput, 0);
		if (timer->Get() - timey >= 2)
		{
			hopper_zero->Set(1);
			hopper_one->Set(0);
		}
		std::cout<<"Not yet in timer->Get() if statement"<<std::endl;		
		if (timer->Get() - timey >= 4){
			std::cout<<"Inside timer->Get() if statement"<<std::endl;
			hopper_zero->Set(0);
			hopper_one->Set(1);
			wipe();
			std::cout<<"Just finished wiping it"<<std::endl;
		}
	}
}

void Auto::turn(bool b_clockwise, int i_degrees){
	left_i_total_encoder_counts = (3714) * 0.25;
	right_i_total_encoder_counts = (3109) * 0.25;
	/*if (b_clockwise)
	{
		left_output = i_total_encoder_counts;
		right_output = i_total_encoder_counts;
	}
	if (!b_clockwise)
	{
		left_output = -i_total_encoder_counts;
		right_output = -i_total_encoder_counts;
	}*/
	talon_left->Set(ControlMode::Velocity, 0.25*i_bot_velocity_max);
	talon_right->Set(ControlMode::Velocity, 0.25*i_bot_velocity_max);
	if (abs(abs(left_i_total_encoder_counts) - abs(talon_left->GetSelectedSensorPosition(0))) <= 100 || abs(abs(right_i_total_encoder_counts) - abs(talon_right->GetSelectedSensorPosition(0))) <= 100){
		mode++;
	}
	else{
		talon_left->Set(ControlMode::Position, left_i_total_encoder_counts);
		talon_right->Set(ControlMode::Position, right_i_total_encoder_counts);
	}
}
void Auto::turn_counter(){
	left_i_total_encoder_counts = (3714) * -0.25;
	right_i_total_encoder_counts = (3109) * -0.25;	
	/*if (b_clockwise)
	{
		left_output = i_total_encoder_counts;
		right_output = i_total_encoder_counts;
	}
	if (!b_clockwise)
	{
		left_output = -i_total_encoder_counts;
		right_output = -i_total_encoder_counts;
	}*/
	talon_left->Set(ControlMode::Velocity, -0.25*i_bot_velocity_max);
	talon_right->Set(ControlMode::Velocity, -0.25*i_bot_velocity_max);
	if (abs(abs(left_i_total_encoder_counts) - abs(talon_left->GetSelectedSensorPosition(0))) <= 100 || abs(abs(right_i_total_encoder_counts) - abs(talon_right->GetSelectedSensorPosition(0))) <= 100){
		mode++;
	}
	else{
		talon_left->Set(ControlMode::Position, left_i_total_encoder_counts);
		talon_right->Set(ControlMode::Position, right_i_total_encoder_counts);
	}
}
void Auto::straight(int i_distance_feet){
	i_distance_inches = i_distance_feet * 12;
	i_total_encoder_counts = (i_distance_inches / f_inches_in_one_rotation) * i_encoder_counts_per_one_rotation;
	if (i_distance_feet < 0)
	{
		i_bot_velocity = -1 * i_bot_velocity_max;
	}
	else{
		i_bot_velocity = i_bot_velocity_max;
	}
	talon_left->Set(ControlMode::Velocity, 0.25*i_bot_velocity);
	talon_right->Set(ControlMode::Velocity, -0.25*i_bot_velocity);
	//talon_left->Set(ControlMode::Position, i_total_encoder_counts);
	//talon_right->Set(ControlMode::Position, i_total_encoder_counts);
	
	if (abs(abs(i_total_encoder_counts) - abs(talon_left->GetSelectedSensorPosition(0))) <= 100 || abs(abs(i_total_encoder_counts) - abs(talon_right->GetSelectedSensorPosition(0))) <= 100)
	{
		timey = timer->Get();
		mode++;
	}
}

void Auto::wipe(){ //Zeros the sensors so that you can reset the position
	talon_left->SetSelectedSensorPosition(0, 0, 10);
	talon_right->SetSelectedSensorPosition(0, 0, 10);
	mode++;
}