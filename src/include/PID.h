//Tuning by Kevin Chang

#ifndef PID_H
#define PID_H

#include <WPILib.h>
#include <ctre/Phoenix.h>
#include <iostream>
#include <cmath>

class PID{
	public:
		PID(TalonSRX* drive_right, TalonSRX* drive_left, TalonSRX *flipper) : drive_right(drive_right), drive_left(drive_left), flipper(flipper) {};
		
		void run_PID();

	private:
		TalonSRX* drive_right;
		TalonSRX *drive_left;
		TalonSRX *flipper;
};
#endif