#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *stick;
	Joystick *m_driveStick;
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
	JoystickButton *platformInOut;
	JoystickButton *setConveyorLowered;

	bool m_isPracticeBot;

public:
	OI(bool isPracticeBot);
	Joystick *getStick();
	Joystick *getDriveStick();
};

#endif
