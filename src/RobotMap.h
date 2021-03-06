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
const int LIFTERBOTTOM_PRACTICE = 111;
const int LIFTERTOP_PRACTICE = 1950;
const int GRABHEIGHTFLOOR_PRACTICE = 104; //need
const int GRABHEIGHTSCORINGPLATFORM_PRACTICE = 125;
const int GRABHEIGHTCONVEYORPLATFORM_PRACTICE = 305;
const int PLACEHEIGHT_PRACTICE = 975;
const int PLACEHEIGHTSCORINGPLATFORM_PRACTICE = 1820;
const int PLACEHEIGHTCONVEYORPLATFORM_PRACTICE = 2873;
const int HOLDHEIGHT_PRACTICE = 1700;
const int PLATFORMHOLDHEIGHT_PRACTICE = 726;
const int HEIGHTTOLERANCE_PRACTICE = 50; //Test this value

const int LIFTERBOTTOM_COMPETITION = 50;
const int LIFTERTOP_COMPETITION = 1950;
const int GRABHEIGHTFLOOR_COMPETITION = 104;
const int GRABHEIGHTPLATFORM_COMPETITION = 125; //Need to find value
const int GRABHEIGHTCONVEYORPLATFORM_COMPETITION = 175; //Was 300
const int PLACEHEIGHT_COMPETITION = 975;
const int PLACEHEIGHTPLATFORM_COMPETITION = 500; //Not Used
const int HOLDHEIGHT_COMPETITION = 1700;
const int HEIGHTTOLERANCE_COMPETITION = 100; //Need to find value
const int PLACEHEIGHTSCORINGPLATFORM_COMPETITION = 500; //Not Used
const int PLACEHEIGHTCONVEYORPLATFORM_COMPETITION = 500; //Not Used
const int PLATFORMHOLDHEIGHT_COMPETITION = 726; //Need to find value


//Lifter Speeds
const float SQUEEZYMOTORLIFTUPSPEED_LOW = 0.80;
const float SQUEEZYMOTORLIFTUPSPEED_MEDIUM = 0.625;
const float SQUEEZYMOTORLIFTUPSPEED_HIGH = 1.0;
const float SQUEEZYMOTORLIFTDOWNSPEED = -0.1;


//Buttons
const int PUSHOUTINBUTTON = 1; //Pusher
const int RUNCONVEYORBUTTON = 2; //Conveyor
const int REVERSECONVEYORBUTTON = 3;//Conveyor
const int STARTFULLAUTOBUTTON = 4;//All
const int PAUSEAUTO = 5;//All
//No button on 6
const int HOLDHEIGHTBUTTON = 7; //Lifter
const int LOWERCONVEYORBUTTON = 8; //Conveyor
const int GRABHEIGHTSCORINGPLATFORMBUTTON = 9; //Lifter
const int MANUALRAISECONVEYORBUTTON = 10; //Conveyor
const int GRABHEIGHTCONVEYORPLATFORMBUTTON = 11; //Lifter
const int MANUALLOWERCONVEYORBUTTON = 12;
const int SETCONVEYORLOWEREDBUTTON = 19;
const int PLATFORMINOUTBUTTON = 20;

//For drive controller
const int ENDSTACKBUTTON = 2;//All
const int PAUSELIFTERAUTO = 3;//All but conveyor

//Variables
const double DISTANCEPERPULSE = 0.07536;


#endif
