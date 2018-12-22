#include <WPILib.h>
#include <ctre/Phoenix.h>
#include <iostream>
#include <cmath>

#include <togglemotor.h>
#include <togglepneu.h>
#include <pressandhold.h>

#include <flipper.h>
#include <hopper.h>
#include <prematch.h>
#include <intake.h>
#include <PID.h>
#include <drivebase.h>
#include <auto.h>

using namespace frc;

class Robot: public IterativeRobot {
    TalonSRX *drive_talon_right_enc, *drive_talon_left_enc, *drive_talon_right_noenc, *drive_talon_left_noenc, *intake_talon_noenc, *flipper_talon_enc;
    Solenoid *hopper_solenoid, *hopper_solenoid_two;
    Joystick *joystick;

    ToggleMotor *drive_toggle_right_enc, *drive_toggle_left_enc, *drive_toggle_right_noenc, *drive_toggle_left_noenc, *flipper_toggle_enc, *intake_toggle_noenc;
    TogglePneu *hopper_toggle, *hopper_toggle_two;
    PressAndHold *intake_hold;
    
    Intake *intake;
    Flipper *flipper;
    Hopper *hopper, *hopper_two;
    Drivebase *drivebase;
    PrematchPrep *prematch;
    Timer *timer;
    PID *pid;
    Auto *autonomous;

    void RobotInit() {
        drive_talon_right_enc = new TalonSRX(6);
        drive_talon_left_enc = new TalonSRX(2);
        drive_talon_right_noenc = new TalonSRX(5);
        drive_talon_left_noenc = new TalonSRX(1);
        flipper_talon_enc = new TalonSRX(4);
        intake_talon_noenc = new TalonSRX(3);
        drive_talon_right_noenc->Set(ControlMode::Follower, 6);
        drive_talon_left_noenc->Set(ControlMode::Follower, 2);

        hopper_solenoid = new Solenoid(0);
        hopper_solenoid_two = new Solenoid(1);

        joystick = new Joystick(0);

        drive_toggle_right_enc = new ToggleMotor(joystick, drive_talon_right_enc);
        drive_toggle_left_enc = new ToggleMotor(joystick, drive_talon_left_enc);
        drive_toggle_right_noenc = new ToggleMotor(joystick, drive_talon_right_noenc);
        drive_toggle_left_noenc = new ToggleMotor(joystick, drive_talon_left_noenc);
        flipper_toggle_enc = new ToggleMotor(joystick, flipper_talon_enc);
        intake_toggle_noenc = new ToggleMotor(joystick, intake_talon_noenc);

        hopper_toggle = new TogglePneu(joystick, hopper_solenoid);
        hopper_toggle_two = new TogglePneu(joystick, hopper_solenoid_two);

        intake_hold = new PressAndHold(joystick, intake_talon_noenc);

        intake = new Intake(intake_hold, intake_talon_noenc, joystick);

        flipper = new Flipper(joystick, flipper_talon_enc);

        hopper = new Hopper(hopper_toggle, hopper_solenoid, hopper_solenoid_two, joystick);

        drivebase = new Drivebase(joystick, drive_talon_right_enc, drive_talon_left_enc);

        prematch = new PrematchPrep(drive_talon_right_enc, drive_toggle_right_enc,
                                    drive_talon_right_noenc, drive_toggle_right_noenc,
                                    drive_talon_left_enc, drive_toggle_left_enc,
                                    drive_talon_left_noenc, drive_toggle_left_noenc,
                                    intake_talon_noenc, intake_toggle_noenc,
                                    flipper_talon_enc, flipper_toggle_enc,
                                    hopper_solenoid, hopper_solenoid_two, joystick);
        timer = new Timer();
        pid = new PID(drive_talon_left_enc, drive_talon_right_enc, flipper_talon_enc);
        pid->run_PID();
        autonomous = new Auto(drive_talon_left_enc, drive_talon_right_enc, intake_talon_noenc, timer, hopper_solenoid, hopper_solenoid_two);

        std::cout<<"All the code + auto v. 20"<<std::endl;

    }
    void AutonomousInit() {
        timer->Start();
        drive_talon_left_enc->SetSelectedSensorPosition(0, 0, 10);
        drive_talon_right_enc->SetSelectedSensorPosition(0, 0, 10);
        autonomous->mode = 1;
    }
    void AutonomousPeriodic() {
        autonomous->run_auto();

        //autonomous->basic_auto();
    }
    void TeleopInit() { 
        flipper_talon_enc->SetSelectedSensorPosition(0, 0, 10);
    }
    void TeleopPeriodic() {
        prematch->run_prematch();
        intake->intake_options(0.25);
        intake->intake_reverse(0.25);
        drivebase->run_drive(0.8, 4, 1, 1, -1);
        flipper->run_flipper(0, 15000, 0 ,0,0,0,0,0);
        hopper->run_hopper();

    } 
    void DisabledInit() {
    }
    void DisabledPeriodic() { }
    };
    START_ROBOT_CLASS(Robot);
 