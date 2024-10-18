#include "Constants.hpp"
#include "Drivetrain.hpp"
#include "MobileClamp.hpp"
#include "pros/device.hpp"
#include "pros/motors.hpp"
#include "pros/motor_group.hpp"
#include "Intake.hpp"


DriveTrain dt = DriveTrain();
Intake Is1 = Intake();
MobileClamp mbc = MobileClamp();
//void initialize() {
//	pros::lcd::initialize();
//	pros::lcd::set_text(1, "Hello PROS User!");

//	pros::lcd::register_btn1_cb(on_center_button);
//}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
    bool mbc_bool = false;
    while(true){
        //--------------------INTAKE STAGE 1 ROTATION LOGIC-------------------------
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){

            Is1.IntakeRotation(Intake1RotationVoltage);

        }else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){

            Is1.IntakeRotation(-Intake1RotationVoltage); // reverses the spin of the motor

        } else {
            Is1.IntakeRotation(0);
        }

        //------------------- MOBILE CLAMP LOGIC------------------------------------

        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            mbc_bool = !mbc_bool;
            mbc.setValue(mbc_bool);
        }

        //-------------------  ARCADE DRIVE TRAIN LOGIC ----------------------------------
        int8_t left = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
        int8_t right = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        dt.arcadeDrive(left,right);

        pros::delay(10);
    }
}


