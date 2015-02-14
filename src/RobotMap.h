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


//Squeezy Lifter
const int SWITCHOPENCLOSEPIN = 2;  //Live Window missing
const int SWITCHHASTOTEPIN = 3;    //Live Window missing
const int STRINGPOTPIN = 0;
const int MOTORLIFT = 2;
const int SQUEEZYPISTONOPENCLOSE_A = 2;
const int SQUEEZYPISTONOPENCLOSE_B = 3;
const int LIFTERBRAKE_A = 6;
const int LIFTERBRAKE_B = 7;
const int SQUEEZYPUSHERFRONTBACK = 4;


const int LIFTERBOTTOM_PRACTICE = 125;
const int LIFTERTOP_PRACTICE = 3450; //2100
const int GRABHEIGHT_PRACTICE = 225; //325
const int COOPHEIGHT_PRACTICE = 1200; //924
const int PLACEHEIGHT_PRACTICE = 1900; //1824
const int HOLDHEIGHT_PRACTICE = 3200; //2000

const int LIFTERBOTTOM_COMPETITION = 73;
const int LIFTERTOP_COMPETITION = 1938;
const int GRABHEIGHT_COMPETITION = 225; //74
const int COOPHEIGHT_COMPETITION = 1200; //Not Set Yet
const int PLACEHEIGHT_COMPETITION = 904;
const int HOLDHEIGHT_COMPETITION = 1557;

const float SQUEEZYMOTORLIFTUPSPEED = 1.0;
const float SQUEEZYMOTORLIFTDOWNSPEED = 0.3;

//Pusher (Salt and Pepper)
const int PUSHERPISTON_A = 4;
const int PUSHERPISTON_B = 5;
const int PUSHERPOSITION = 4;  //Live Window missing
const int PUSHERLIMITSWITCH = 5;

//Conveyor


//Other
const int PRINTSTUFFBUTTON = 5;

//Buttons

//Pusher Buttons
const int PUSHOUTBUTTON = 1;
const int PUSHINBUTTON = 2;

//Drive Train Buttons
const int SHIFTHIGHBUTTON = 8;
const int SHIFTLOWBUTTON = 10;

//Squeezy Buttons
const int TOGGLESQUEEZEBUTTON = 6;

//Lifter Buttons
const int GRABHEIGHTBUTTON = 7;
const int PLACEHEIGHTBUTTON = 9;
const int HOLDHEIGHTBUTTON = 11;

#endif
