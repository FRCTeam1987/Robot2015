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
	JoystickButton *pushOut;
	JoystickButton *pushIn;
	JoystickButton *grabHeight;
	JoystickButton *placeHeight;
	JoystickButton *holdHeight;

	bool m_isPracticeBot;
public:
	OI(bool isPracticeBot);
	Joystick *getStick();
};

#endif
