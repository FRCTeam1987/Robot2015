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

const int PRACTICEBOTJUMPER = 9;

//Drive Train
const int LEFTDRIVEMOTOR = 0;
const int RIGHTDRIVEMOTOR = 1;
//const int SHIFT_A = 0;
const int SHIFT_B = 1;
const int GYROPIN = 1;
const int ENCODER_PIN_A = 1;
const int ENCODER_PIN_B = 0;
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


const int LIFTERBOTTOM_PRACTICE = 75;
const int LIFTERTOP_PRACTICE = 3450;
const int GRABHEIGHTFLOOR_PRACTICE = 150;
const int GRABHEIGHTPLATFORM_PRACTICE = 0;
const int COOPHEIGHT_PRACTICE = 1200;
const int PLACEHEIGHT_PRACTICE = 1900;
const int HOLDHEIGHT_PRACTICE = 3200;

const int LIFTERBOTTOM_COMPETITION = 50;
const int LIFTERTOP_COMPETITION = 1950;
const int GRABHEIGHTFLOOR_COMPETITION = 104;
const int GRABHEIGHTPLATFORM_COMPETITION = 0;
const int COOPHEIGHT_COMPETITION = 550;
const int PLACEHEIGHT_COMPETITION = 975;
const int HOLDHEIGHT_COMPETITION = 1650;

const float SQUEEZYMOTORLIFTUPSPEED_LOW = -0.5;
const float SQUEEZYMOTORLIFTUPSPEED_MEDIUM = -0.625;
const float SQUEEZYMOTORLIFTUPSPEED_HIGH = -0.75;
const float SQUEEZYMOTORLIFTDOWNSPEED = -0.2;

//Pusher (Salt and Pepper)
const int PUSHERPISTON_A = 4;
const int PUSHERPISTON_B = 5;
const int PUSHERPOSITION = 4;  //Live Window missing
const int PUSHERLIMITSWITCH = 5;

//Conveyor
const int BREAKTOTEENTERPIN = 6;
const int BREAKTOTEEXITPIN = 7;
const int MOTORLOWERCONVEYORPIN = 1;
const int MOTORCONVEYORPIN = 3;
const int AIRPLATFORMPIN = 0;
const int CONVEYORMOTOR_A = 2;
const int CONEYORMOTOR_B = 3;
const int CONVEYORSWITCHPIN = 8;

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
const int BOTTOMSTACKBUTTON = 12;

#endif
