#pragma once

#include <cstdint>
namespace Constants {

//----------------------MOTOR CONSTANTS------------------

//---------------------LEFT MOTOR PORTS-----------------------

// assign all the motors and their respective ports

//left is the side with the pneumatic attached to it(The organge cylinder ). front is the side with the intake
static constexpr unsigned char fl_p = 11; //10 represents the port number
static constexpr unsigned char ml_p = 12;
static constexpr unsigned char bl_p = 13;

//---------------------RIGHT MOTOR PORTS----------------------

static constexpr unsigned char fr_p = 1;
static constexpr unsigned char mr_p = 2;
static constexpr unsigned char br_p = 3;

//---------------------INTAKE MOTOR PORTS---------------------

const uint8_t intakeStage1_p = 4; 
static constexpr unsigned char intakeStage2_p = 5;

//--------------------INTAKE MOTOR VARIABLES----------------

static constexpr int Intake1RotationVoltage = 170; // rotation speed for when 

//---------------------ROBOT KEYBINDS-------------------------

//Ex: static constexpr  button_name  = 'A';

//---------------------MISC-----------------------------------

static constexpr double pi = 3.141592653586; // pi
static const double radToDeg = 180/pi;

static constexpr char threshold = 11;

static constexpr float trackwidth = 9.9f; // The distance between both the left and an right motors
static constexpr float wheelDiameter = 2.25f; // Diameter of drive wheels
static constexpr double unitsToRevolution = 642.8571429; // Motor units per revolution for drive wheels (900 * 5/7)
static const double inchesPerTick = wheelDiameter*pi/unitsToRevolution; // The inches per tick for the drive encoders
}