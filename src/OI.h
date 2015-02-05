#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *stick;
	JoystickButton *shiftHiButton;
	JoystickButton *shiftLowButton;
	JoystickButton *printStuff;
	JoystickButton *toggleSqueeze;


public:
	OI();
	Joystick *getStick();
};

#endif
