#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *stick;
	JoystickButton *printStuff;
	JoystickButton *toggleSqueeze;
	JoystickButton *pushOut;
	JoystickButton *pushIn;
	JoystickButton *grabHeight;
	JoystickButton *placeHeight;
	JoystickButton *holdHeight;
//	JoystickButton *bottomStack;

	bool m_isPracticeBot;
public:
	OI(bool isPracticeBot);
	Joystick *getStick();
};

#endif
