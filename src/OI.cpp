#include <Commands/DriveTrain/ShiftLow.h>
#include "OI.h"
#include "RobotMap.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/SqueezyLifter.h"
#include "Commands/DriveTrain/ShiftHi.h"
#include "Commands/PrintStuff.h"
#include "Commands/SqueezyLifter/SqueezyOpenClose.h"
#include "Commands/SqueezyLifter/SqueezyToggle.h"
#include "Commands/SqueezyLifter/SqueezyUpDown.h"
#include "Commands/SqueezyLifter/EngageLifterBrake.h"
#include "Commands/SqueezyLifter/ReleaseLifterBrake.h"
#include "Commands/Pusher/PushInOut.h"

OI::OI(bool isPracticeBot)
{
	m_isPracticeBot = isPracticeBot;

	// Process operator interface input here.

	stick = new Joystick(0);
	shiftHiButton = new JoystickButton(stick, SHIFTHIGHBUTTON);
	shiftLowButton = new JoystickButton(stick, SHIFTLOWBUTTON);
	printStuff = new JoystickButton(stick, PRINTSTUFFBUTTON);
	toggleSqueeze = new JoystickButton(stick, TOGGLESQUEEZEBUTTON);
	pushOut = new JoystickButton(stick, PUSHOUTBUTTON);
	pushIn = new JoystickButton(stick, PUSHINBUTTON);
	grabHeight = new JoystickButton(stick, GRABHEIGHTBUTTON);
	placeHeight = new JoystickButton(stick, PLACEHEIGHTBUTTON);
	holdHeight = new JoystickButton(stick, HOLDHEIGHTBUTTON);

	shiftHiButton->WhenPressed(new ShiftHi());
	shiftLowButton->WhenPressed(new ShiftLow());
	printStuff->WhenPressed(new PrintStuff());
	toggleSqueeze->WhenPressed(new SqueezyToggle());
	pushOut->WhenPressed(new PushInOut(PushInOut::kOut));
	pushIn->WhenPressed(new PushInOut(PushInOut::kIn));

	int GrabHeight, HoldHeight;
	if(m_isPracticeBot)
	{
		GrabHeight = GRABHEIGHT_PRACTICE;
		HoldHeight = HOLDHEIGHT_PRACTICE;
	}
	else
	{
		GrabHeight = GRABHEIGHT_COMPETITION;
		HoldHeight = HOLDHEIGHT_COMPETITION;
	}

	SmartDashboard::PutData("SqueezyLifter - Close Squeezy", new SqueezyOpenClose(SqueezyOpenClose::kClose));
	SmartDashboard::PutData("SqueezyLifter - Open Squeezy", new SqueezyOpenClose(SqueezyOpenClose::kOpen));
	SmartDashboard::PutData("Drive Train - Shift High", new ShiftHi());
	SmartDashboard::PutData("Drive Train - Shift Low", new ShiftLow());
	SmartDashboard::PutData("Print Stuff", new PrintStuff());
	SmartDashboard::PutData("Pusher Push Out", new PushInOut(PushInOut::kOut));
	SmartDashboard::PutData("Pusher In", new PushInOut(PushInOut::kIn));
	SmartDashboard::PutData("SqueezyLifter - Grab Height", new SqueezyUpDown(GrabHeight));
	SmartDashboard::PutData("SqueezyLifter - Hold Height", new SqueezyUpDown(HoldHeight));
	SmartDashboard::PutData("SqueezyLifter - Engage Brake", new EngageLifterBrake());
	SmartDashboard::PutData("SqueezyLifter - Release Brake", new ReleaseLifterBrake());
	SmartDashboard::PutNumber("Lifter Pot", CommandBase::squeezyLifter->getLifterHeight());

}

Joystick* OI::getStick()
{
	return stick;
}
