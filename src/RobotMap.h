#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;


//Drive Train
const int LEFTDRIVEMOTOR = 0;
const int RIGHTDRIVEMOTOR = 1;
const int SHIFT_A = 0;
const int SHIFT_B = 1;
const int GYROPIN = 1;
const int ENCODER_PIN_A = 0;
const int ENCODER_PIN_B = 1;
const double DISTANCEPERPULSE = 0.07536;
const int WALLFINDER = 5;      //Live Window missing
const int PLATFORMFINDER = 6;  //Live Window missing

const int SHIFTHIGHBUTTON = 7;
const int SHIFTLOWBUTTON = 8;

//Squeezy Lifter
const int SWITCHOPENCLOSEPIN = 2;  //Live Window missing
const int SWITCHHASTOTEPIN = 3;    //Live Window missing
const int STRINGPOTPIN = 0;
const int MOTORLIFT = 2;
const int SQUEEZYPISTONOPENCLOSE_A = 2;
const int SQUEEZYPISTONOPENCLOSE_B = 3;

const int TOTEHEIGHT = 15;


//Pusher (Salt and Pepper)
const int PUSHERPISTON_A = 4;
const int PUSHERPISTON_B = 5;
const int PUSHERPOSITION = 4;  //Live Window missing

//Conveyor




#endif
