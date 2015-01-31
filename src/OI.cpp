#include <Commands/DriveTrain/ShiftLow.h>
#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveTrain/ShiftHi.h"
#include "Commands/PrintStuff.h"
#include "Subsystems/DriveTrain.h"

OI::OI()
{
	// Process operator interface input here.

	stick = new Joystick(0);
	shiftHiButton = new JoystickButton(stick, SHIFTHIGHBUTTON);
	shiftLowButton = new JoystickButton(stick, SHIFTLOWBUTTON);

	shiftHiButton->WhenPressed(new ShiftHi());
	shiftLowButton->WhenPressed(new ShiftLow());

	SmartDashboard::PutData("Shift High", new ShiftHi());
	SmartDashboard::PutData("Shift Low", new ShiftLow());
	SmartDashboard::PutData("Print Stuff", new PrintStuff());
}

Joystick *OI::getStick()
{
	return stick;
}
