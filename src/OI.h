#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *stick;
	JoystickButton *shiftHiButton;
	JoystickButton *defecateLoButton;

public:
	OI();
	Joystick *getStick();
};

#endif
