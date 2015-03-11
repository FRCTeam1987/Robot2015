#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *stick;
//	JoystickButton *printStuff;
//	JoystickButton *toggleSqueeze;
	JoystickButton *pusher;
//	JoystickButton *pushIn;
	JoystickButton *grabHeightConveyorPlatform;
	JoystickButton *grabHeightScoringPlatform;
	JoystickButton *holdHeight;
	JoystickButton *runConveyorForward;
	JoystickButton *runConveyorBackward;
	JoystickButton *lowerConveyor;
//	JoystickButton *raiseConveyor;
	JoystickButton *startFullAuto;
	JoystickButton *pauseAuto;
	JoystickButton *unpauseAuto;
	JoystickButton *manualLowerConveyor;
	JoystickButton *manualRaiseConveyor;

	bool m_isPracticeBot;

public:
	OI(bool isPracticeBot);
	Joystick *getStick();
};

#endif
