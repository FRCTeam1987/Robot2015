#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

//DIO
const int ENCODER_PIN_B = 0; //Drive Train
const int ENCODER_PIN_A = 1; //Drive Train
const int PUSHERPOSITION = 2; //Pusher
const int SWITCHHASTOTEPIN = 3; //Squeezy Lifter
//No Sensor in DIO 4
const int PUSHERLIMITSWITCH = 5; //Pusher
const int BREAKTOTEENTERPIN = 6; //Conveyer
const int BREAKTOTEEXITPIN = 7; //Conveyer
//No Sensor in DIO 8
const int PRACTICEBOTJUMPER = 9; //JUMPER


//Analog
const int STRINGPOTPIN = 0; //Squeezy Lifter
const int GYROPIN = 1; //Drive Train


//PWM
const int LEFTDRIVEMOTOR = 0; //Drive Train
const int RIGHTDRIVEMOTOR = 1; //Drive Train
//No PWM in 2
const int CONVEYORMOTOR_ROLLER = 3; //Conveyer


//CAN BUS
const int CONVEYORMOTOR_WINCH = 1; //Conveyer
const int MOTORLIFT = 2; //Squeezy Lifter
const int CONVEYORMOTOR_BELT = 3; //Conveyer


//PCM
const int PLATFORM_IN = 0; //Conveyor
const int PLATFORM_OUT = 1; //Conveyer
const int SQUEEZYPISTONOPENCLOSE_A = 2; //Squeezy Lifter
const int SQUEEZYPISTONOPENCLOSE_B = 3; //Squeezy Lifter
const int PUSHERPISTON_A = 4; //Pusher
const int PUSHERPISTON_B = 5; //Pusher
const int LIFTERBRAKE_A = 6; //Squeezy Lifter
const int LIFTERBRAKE_B = 7; //Squeezy Lifter


//Lifter Heights
const int LIFTERBOTTOM_PRACTICE = 159;
const int LIFTERTOP_PRACTICE = 3500;
const int GRABHEIGHTFLOOR_PRACTICE = 125; //need
const int GRABHEIGHTSCORINGPLATFORM_PRACTICE = 267;
const int GRABHEIGHTCONVEYORPLATFORM_PRACTICE = 950;
const int PLACEHEIGHT_PRACTICE = 1900;
const int PLACEHEIGHTSCORINGPLATFORM_PRACTICE = 1820;
const int PLACEHEIGHTCONVEYORPLATFORM_PRACTICE = 2873;
const int HOLDHEIGHT_PRACTICE = 3389;
const int PLATFORMHOLDHEIGHT_PRACTICE = 1500;
const int HEIGHTTOLERANCE_PRACTICE = 150; //Test this value

const int LIFTERBOTTOM_COMPETITION = 50;
const int LIFTERTOP_COMPETITION = 1950;
const int GRABHEIGHTFLOOR_COMPETITION = 104;
const int GRABHEIGHTPLATFORM_COMPETITION = 219; //Need to find value
const int GRABHEIGHTCONVEYORPLATFORM_COMPETITION = 0; //Need to find value
const int PLACEHEIGHT_COMPETITION = 975;
const int PLACEHEIGHTPLATFORM_COMPETITION = 0; //Need to find value
const int HOLDHEIGHT_COMPETITION = 1650;
const int HEIGHTTOLERANCE_COMPETITION = 100; //Need to find value
const int PLACEHEIGHTSCORINGPLATFORM_COMPETITION = 0;
const int PLACEHEIGHTCONVEYORPLATFORM_COMPETITION = 0;
const int PLATFORMHOLDHEIGHT_COMPETITION = 0; //Need to find value


//Lifter Speeds
const float SQUEEZYMOTORLIFTUPSPEED_LOW = -0.4242;
const float SQUEEZYMOTORLIFTUPSPEED_MEDIUM = -0.625;
const float SQUEEZYMOTORLIFTUPSPEED_HIGH = -0.75;
const float SQUEEZYMOTORLIFTDOWNSPEED = -0.1;


//Buttons
const int PUSHOUTBUTTON = 1; //Pusher
const int PUSHINBUTTON = 2; //Pusher
const int TOGGLESQUEEZEBUTTON = 6; //Squeezy Lifter
const int GRABHEIGHTBUTTON = 11; //Lifter
const int PLACEHEIGHTBUTTON = 9; //Lifter
const int HOLDHEIGHTBUTTON = 7; //Lifter
const int BOTTOMSTACKBUTTON = 12; //Lifter
const int RAISECONVEYORBUTTON = 4; //Conveyor
const int LOWERCONVEYORBUTTON = 3; //Conveyor
const int RUNCONVEYORBUTTON = 8; //Conveyor
const int PRINTSTUFFBUTTON = 5; //Print Stuff


//Variables
const double DISTANCEPERPULSE = 0.07536;


#endif
