#pragma once

#include "Constants.hpp"
#include "pros/motors.hpp"
#include "pros/motor_group.hpp"

using namespace Constants;
using namespace pros;

class DriveTrain {
    // LEFT MOTORS
    Motor fl_mtr = Motor(fl_p); // front left motor
    Motor ml_mtr = Motor(ml_p); // middle left motor
    Motor bl_mtr = Motor(bl_p); // back left motor

    // RIGHT MOTORS
    Motor fr_mtr = Motor(fr_p); // front right motor
    Motor mr_mtr = Motor(mr_p); // middle right motor
    Motor br_mtr = Motor(br_p); // back right motor

    // MOTOR GROUPS
    MotorGroup left_group {{fl_p, ml_p, bl_p}}; // create motor groups
    MotorGroup right_group {{fr_p, mr_p, br_p}};

public:
    DriveTrain() {
        // Boot up DriveTrain by setting motors to zero (tare_position)
        left_group.set_brake_mode_all(E_MOTOR_BRAKE_HOLD);
        right_group.set_brake_mode_all(E_MOTOR_BRAKE_HOLD);

        left_group.tare_position();
        right_group.tare_position();

        // Initialize motor movement if needed
        //left_group.move(127);
        //right_group.move(127); // Add this for the right group

    }

    void arcadeDrive(int8_t leftY, int8_t rightX) {
        // Threshold logic to ignore small joystick values
        leftY = abs(leftY) < threshold ? 0 : leftY;
        rightX = abs(rightX) < threshold ? 0 : rightX;

        // Move motors using arcade drive logic
        left_group.move(leftY + rightX);
        right_group.move(leftY - rightX);

    }
};


/**

#pragma once

#include "Constants.hpp"
#include "pros/motors.hpp"
#include "pros/motor_group.hpp"


using namespace Constants;
using namespace pros;


class DriveTrain {

    //LEFT MOTORS
    Motor fl_mtr = Motor(fl_p);//front right motor
    Motor ml_mtr = Motor(ml_p);// false represnts if the motor is reversed or not
    Motor bl_mtr = Motor(bl_p);// back left motor
    //RIGHT MOTORS
    Motor fr_mtr = Motor(fl_p);//front left motor
    Motor mr_mtr = Motor(ml_p);
    Motor br_mtr = Motor(br_p);//back right motor
    //MOTOR GROUPS


    MotorGroup left_group {{fl_p, ml_p,bl_p}};//create motor groups
    MotorGroup right_group {{fr_p, mr_p,br_p}};

    AbstractMotor abs_mtr_group = left_group;
    MotorGroup new_mg = (MotorGroup) abs_mtr_group

    //MotorGroup first_mg({1, -2}); //Creates a motor on port 1  and a reversed motor on port 2 with
	 //*  with both motors using the green gearset and degrees as the encoder units
	 //* 	AbstractMotor abs_mtr_group = first_mg;
	// * 	MotorGroup new_mg = (MotorGroup) abs_mtr_group;

    public:
    DriveTrain() {// boot up DriveTrain by settings motors to zero(tare_position)
        left_group.set_brake_mode(E_MOTOR_BRAKE_HOLD);
        right_group.set_brake_mode(E_MOTOR_BRAKE_HOLD);

        left_group.tare_position();// tare_position resets the motor position to 0
        right_group.tare_position();
        left_group.move(127);

    }

    void arcadeDrive(int8_t leftY, int8_t rightX) {
        leftY = abs(leftY)<threshold ? 0 : leftY;
        rightX = abs(rightX)<threshold ? 0 : rightX;
        left_group.move(leftY + rightX);
        right_group.move(leftY - rightX);
    }// arcade drive is for forward and backward movement


    




};
 */
