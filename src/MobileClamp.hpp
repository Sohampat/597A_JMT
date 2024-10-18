#pragma once

#include "Constants.hpp"
#include "pros/adi.hpp"


using namespace Constants;
using namespace pros;



class MobileClamp{
    bool state = false;
    adi::DigitalOut piston = adi::DigitalOut('A');
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