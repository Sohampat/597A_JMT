
#pragma once

#include "Constants.hpp"
#include "pros/motors.hpp"
#include "pros/motor_group.hpp"


using namespace Constants;
using namespace pros;

class Intake{

    Motor intakeStage1_mtr = Motor(intakeStage1_p);
    Motor intakeStage2_mtr = Motor(intakeStage2_p);


    MotorGroup intakeMotorGroup {{intakeStage1_p,intakeStage2_p}};

    
public:
    Intake() {// boot up DriveTrain by settings motors to zero(tare_position)
        intakeMotorGroup.set_brake_mode(E_MOTOR_BRAKE_HOLD);
        intakeMotorGroup.tare_position();
    };

    void IntakeRotation(int RotationSpeed) { // rotates both intakes 
        intakeMotorGroup.move(RotationSpeed);
    }
};



