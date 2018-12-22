//Tuning by Kevin Chang

#include <PID.h>

void PID::run_PID(){
	drive_left->Config_kF(0, 1.6447, 0);
	drive_left->Config_kP(0, 12, 10);
	drive_left->Config_kI(0, 0, 10);
	drive_left->Config_kD(0, 1, 10);

	drive_right->Config_kF(0, 1.5453, 0);
	drive_right->Config_kP(0, 12, 10);
	drive_right->Config_kI(0, 0, 10);
	drive_right->Config_kD(0, 1, 10);

	flipper->Config_kP(0, 1.6, 10);
	flipper->Config_kI(0, 0, 10);
	flipper->Config_kD(0, 0.3, 10);
}