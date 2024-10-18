#pragma once

#include <cstdint>
namespace Constants {

//----------------------MOTOR CONSTANTS------------------

//---------------------LEFT MOTOR PORTS-----------------------

// assign all the motors and their respective ports

//left is the side with the pneumatic attached to it(The organge cylinder ). front is the side with the intake
const uint8_t fl_p = 11; //10 represents the port number
const uint8_t ml_p = 12;
const uint8_t bl_p = 13;

//---------------------RIGHT MOTOR PORTS----------------------

const uint8_t fr_p = 1;
const uint8_t mr_p = 2;
const uint8_t br_p = 3;

//---------------------INTAKE MOTOR PORTS---------------------

const uint8_t intakeStage1_p = 4; 
const uint8_t intakeStage2_p = 5;

//--------------------INTAKE MOTOR VARIABLES----------------

const int8_t Intake1RotationVoltage = 127; // rotation speed for when 

//---------------------ROBOT KEYBINDS-------------------------

//Ex: static constexpr  button_name  = 'A';

//---------------------MISC-----------------------------------


const int8_t threshold = 11;

}