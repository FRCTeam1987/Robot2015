#ifndef XBOXCONTROLLER_H
#define XBOXCONTROLLER_H

#include "Joystick.h"

class XboxController : public Joystick
{
public:
	XboxController(uint32_t port);
	
	bool GetAButton();
	bool GetBButton();
	bool GetXButton();
	bool GetYButton();
	bool GetLBButton();
	bool GetRBButton();
	bool GetBackButton();
	bool GetStartButton();
	bool GetLeftJoyButton();
	bool GetRightJoyButton();
	float GetLeftJoyX();
	float GetLeftJoyY();
	float GetRightJoyX();
	float GetRightJoyY();
	
	virtual float GetX(JoystickHand hand = kRightHand);
	virtual float GetY(JoystickHand hand = kRightHand);
};

#endif // end of XBOXCONTROLLER_H
