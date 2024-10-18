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

    public:
    DriveTrain() {// boot up DriveTrain by settings motors to zero(tare_position)
        left_group.set_brake_mode(E_MOTOR_BRAKE_HOLD);
        right_group.set_brake_mode(E_MOTOR_BRAKE_HOLD);

        left_group.tare_position();// tare_position resets the motor position to 0
        right_group.tare_position();


    }

    void arcadeDrive(int8_t leftY, int8_t rightX) {
        leftY = abs(leftY)<threshold ? 0 : leftY;
        rightX = abs(rightX)<threshold ? 0 : rightX;
        left_group.move(leftY + rightX);
        right_group.move(leftY - rightX);
    }// arcade drive is for forward and backward movement




};