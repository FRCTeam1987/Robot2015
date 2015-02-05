#include <Commands/DriveTrain/ShiftLow.h>
#include "OI.h"
#include "RobotMap.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/SqueezyLifter.h"
#include "Commands/DriveTrain/ShiftHi.h"
#include "Commands/PrintStuff.h"
#include "Commands/SqueezyLifter/SqueezyOpenClose.h"
#include "Commands/SqueezyLifter/SqueezyToggle.h"
#include "Commands/Pusher/PushInOut.h"

OI::OI()
{
	// Process operator interface input here.

	stick = new Joystick(0);
	shiftHiButton = new JoystickButton(stick, SHIFTHIGHBUTTON);
	shiftLowButton = new JoystickButton(stick, SHIFTLOWBUTTON);
	printStuff = new JoystickButton(stick, PRINTSTUFFBUTTON);
	toggleSqueeze = new JoystickButton(stick, TOGGLESQUEEZEBUTTON);

	shiftHiButton->WhenPressed(new ShiftHi());
	shiftLowButton->WhenPressed(new ShiftLow());
	printStuff->WhenPressed(new PrintStuff());
	toggleSqueeze->WhenPressed(new SqueezyToggle());

	SmartDashboard::PutData("SqueezyLifter - Close Squeezy", new SqueezyOpenClose(false));
	SmartDashboard::PutData("SqueezyLifter - Open Squeezy", new SqueezyOpenClose(true));
	SmartDashboard::PutData("Drive Train - Shift High", new ShiftHi());
	SmartDashboard::PutData("Drive Train - Shift Low", new ShiftLow());
	SmartDashboard::PutData("Print Stuff", new PrintStuff());
	SmartDashboard::PutData("Pusher Push Out", new PushInOut(true));
	SmartDashboard::PutData("Pusher In", new PushInOut(false));
}

Joystick* OI::getStick()
{
	return stick;
}
