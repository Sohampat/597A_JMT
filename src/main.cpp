#include "Constants.hpp"
#include "Drivetrain.hpp"
#include "MobileClamp.hpp"
#include "pros/device.hpp"
#include "pros/motors.hpp"
#include "pros/motor_group.hpp"
#include "Intake.hpp"
#include <iostream>


Controller master(E_CONTROLLER_MASTER);
DriveTrain dt = DriveTrain();
Intake intake = Intake();
MobileClamp mbc = MobileClamp();

void disabled() {}

void competition_initialize() {}

void autonomous() {}


void opcontrol() {
    bool clampState = false;
    while(true){
        std::cout << "while loop run" << std::endl;
        //--------------------INTAKE STAGE 1 ROTATION LOGIC-------------------------
        if (master.get_digital(E_CONTROLLER_DIGITAL_R1)){

            intake.IntakeRotation(Intake1RotationVoltage);

        }else if (master.get_digital(E_CONTROLLER_DIGITAL_R2)){

            intake.IntakeRotation(-Intake1RotationVoltage); // reverses the spin of the motor

        } else {
            std::cout << "intake rotation to zero" << std::endl;
            intake.IntakeRotation(0);
        }

        //------------------- MOBILE CLAMP LOGIC------------------------------------

        if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) {
            clampState = !clampState;
            mbc.setValue(clampState);
        }

        //-------------------  ARCADE DRIVE TRAIN LOGIC ----------------------------------
        dt.arcadeDrive(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y),master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X));
        std::cout << "what" << std::endl;
        pros::delay(100);
    }
}


