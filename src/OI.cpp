#include <Commands/DriveTrain/ShiftLow.h>
#include "OI.h"
#include "RobotMap.h"
#include "Subsystems/DriveTrain.h"
#include "Commands/DriveTrain/ShiftHi.h"
#include "Commands/PrintStuff.h"
#include "Commands/SqueezyLifter/SqueezyOpenClose.h"


OI::OI()
{
	// Process operator interface input here.

	stick = new Joystick(0);
	shiftHiButton = new JoystickButton(stick, SHIFTHIGHBUTTON);
	shiftLowButton = new JoystickButton(stick, SHIFTLOWBUTTON);

	shiftHiButton->WhenPressed(new ShiftHi());
	shiftLowButton->WhenPressed(new ShiftLow());

	SmartDashboard::PutData("Drive Train - Shift High", new ShiftHi());
	SmartDashboard::PutData("Drive Train - Shift Low", new ShiftLow());
	SmartDashboard::PutData("Print Stuff", new PrintStuff());
//	SmartDashboard::PutData("Squeezy/Lifter - Close Squeezy", new SqueezyClose());
//	SmartDashboard::PutData("Squeezy/Lifter - Open Squeezy", new SqueezyOpen());
}

Joystick *OI::getStick()
{
	return stick;
}
