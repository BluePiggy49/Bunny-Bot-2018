//By Erica Wood

#ifndef AUTO_H
#define AUTO_H

#include <WPILib.h>
#include <ctre/Phoenix.h>
#include <iostream>
#include <cmath>
#include <Timer.h>

class Auto {
	public:
		Auto(TalonSRX* pig, TalonSRX* talon_right, TalonSRX *intake, Timer *timer, Solenoid *hopper_zero, Solenoid *hopper_one)
			:talon_left(pig), talon_right(talon_right), intake(intake), timer(timer), hopper_zero(hopper_zero), hopper_one(hopper_one){};

		void run_auto();
		void basic_auto();
		int mode = 1;
		
	private:
		TalonSRX* talon_left;
		TalonSRX* talon_right;
		TalonSRX *intake;
		Solenoid *hopper_zero, *hopper_one;
		Timer *timer;

		void straight(int i_distance_feet);
		void turn(bool b_clockwise, int i_degrees);
		void wipe();
		void turn_counter();

		int left_i_total_encoder_counts;
		int right_i_total_encoder_counts;
		int i_total_encoder_counts;
		
		//2015 Drive Base

		/*const float f_inches_in_one_rotation = 4 * (3.1415926);
		const int i_encoder_counts_per_one_rotation = 0.5 * (1004 + 1024);
		const int i_encoder_counts_per_robot_rotation = 0.5 * (7891 + 6774);*/

		//Bunny Bot

		const float f_inches_in_one_rotation = 6*3.1415926;
		const int i_encoder_counts_per_one_rotation = (1/6.0) * (859 + 850 + 835 + 857 + 833 + 858);
		const int i_encoder_counts_per_robot_rotation = 0.5 * (3292 + 3869);
		
		int i_distance_inches;
		float timey;
		float f_intake_speed = 1.0;
		int i_bot_velocity;
		int i_bot_velocity_max = 960;
		int left_output;
		int right_output;
};
#endif