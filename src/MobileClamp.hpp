#pragma once

#include "Constants.hpp"
#include "pros/motors.hpp"
#include "pros/motor_group.hpp"
#include "pros/adi.hpp"


using namespace Constants;
using namespace pros;



class MobileClamp{
    bool state = false;
    pros::ADIDigitalOut piston = ADIDigitalOut('A');
    public:
    MobileClamp(){

    }

    void setValue(bool b) {
        piston.set_value(b);
    }

    void clamp() {
        piston.set_value(true);
    }

    void unclamp() {
        piston.set_value(false);
    }
};