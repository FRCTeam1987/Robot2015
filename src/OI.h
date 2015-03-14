#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *stick;
	JoystickButton *pusher;
	JoystickButton *grabHeightConveyorPlatform;
	JoystickButton *grabHeightScoringPlatform;
	JoystickButton *holdHeight;
	JoystickButton *runConveyorForward;
	JoystickButton *runConveyorBackward;
	JoystickButton *lowerConveyor;
	JoystickButton *startFullAuto;
	JoystickButton *pauseAuto;
	JoystickButton *endStack;
	JoystickButton *manualLowerConveyor;
	JoystickButton *manualRaiseConveyor;

	bool m_isPracticeBot;

public:
	OI(bool isPracticeBot);
	Joystick *getStick();
};

#endif
