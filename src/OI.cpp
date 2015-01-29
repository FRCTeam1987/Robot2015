#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveTrain/ShiftHi.h"
#include "Commands/DriveTrain/DefecateLo.h"
#include "Commands/PrintStuff.h"


OI::OI()
{
	// Process operator interface input here.

	stick = new Joystick(0);
	shiftHiButton = new JoystickButton(stick, SHIFTHIGHBUTTON);
	defecateLoButton = new JoystickButton(stick, SHIFTLOWBUTTON);

	shiftHiButton->WhenPressed(new ShiftHi());
	defecateLoButton->WhenPressed(new DefecateLo());

	SmartDashboard::PutData("Shift High", new ShiftHi());
	SmartDashboard::PutData("Defecate Low", new DefecateLo());
	SmartDashboard::PutData("Print Stuff", new PrintStuff());
}

Joystick *OI::getStick()
{
	return stick;
}
