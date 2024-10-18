#include "Constants.hpp"
#include "Drivetrain.hpp"
#include "MobileClamp.hpp"
#include "pros/device.hpp"
#include "pros/motors.hpp"
#include "pros/motor_group.hpp"
#include "Intake.hpp"


DriveTrain dt = DriveTrain();
Intake intake = Intake();
MobileClamp mbc = MobileClamp();

void disabled() {}

void competition_initialize() {}

void autonomous() {}


void opcontrol() {
	Controller master(E_CONTROLLER_MASTER);
    bool clampState = false;
    while(true){
        //--------------------INTAKE STAGE 1 ROTATION LOGIC-------------------------
        if (master.get_digital(E_CONTROLLER_DIGITAL_R1)){

            intake.IntakeRotation(Intake1RotationVoltage);

        }else if (master.get_digital(E_CONTROLLER_DIGITAL_R2)){

            intake.IntakeRotation(-Intake1RotationVoltage); // reverses the spin of the motor

        } else {
            intake.IntakeRotation(0);
        }

        //------------------- MOBILE CLAMP LOGIC------------------------------------

        if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) {
            clampState = !clampState;
            mbc.setValue(clampState);
        }

        //-------------------  ARCADE DRIVE TRAIN LOGIC ----------------------------------
        int8_t left = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
        int8_t right = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);
        dt.arcadeDrive(left,right);

        pros::delay(10);
    }
}


