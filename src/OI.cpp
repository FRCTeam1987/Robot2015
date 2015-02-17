#include "OI.h"
#include "RobotMap.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/SqueezyLifter.h"
#include "Commands/PrintStuff.h"
#include "Commands/SqueezyLifter/SqueezyOpenClose.h"
#include "Commands/SqueezyLifter/SqueezyToggle.h"
#include "Commands/SqueezyLifter/SqueezyUpDown.h"
#include "Commands/SqueezyLifter/EngageLifterBrake.h"
#include "Commands/SqueezyLifter/ReleaseLifterBrake.h"
#include "Commands/SqueezyLifter/LiftTote.h"
#include "Commands/SqueezyLifter/IncrementToteCount.h"
#include "Commands/SqueezyLifter/SixTotePush.h"
#include "Commands/Pusher/PushInOut.h"

OI::OI(bool isPracticeBot)
{
	m_isPracticeBot = isPracticeBot;

	// Process operator interface input here.

	stick = new Joystick(0);
	printStuff = new JoystickButton(stick, PRINTSTUFFBUTTON);
	toggleSqueeze = new JoystickButton(stick, TOGGLESQUEEZEBUTTON);
	pushOut = new JoystickButton(stick, PUSHOUTBUTTON);
	pushIn = new JoystickButton(stick, PUSHINBUTTON);
	grabHeight = new JoystickButton(stick, GRABHEIGHTBUTTON);
	placeHeight = new JoystickButton(stick, PLACEHEIGHTBUTTON);
	holdHeight = new JoystickButton(stick, HOLDHEIGHTBUTTON);
//	bottomStack = new JoystickButton(stick, PRINTSTUFFBUTTON);

	printStuff->WhenPressed(new PrintStuff());
	toggleSqueeze->WhenPressed(new SqueezyToggle());
	pushOut->WhenPressed(new PushInOut(PushInOut::kOut));
	pushIn->WhenPressed(new PushInOut(PushInOut::kIn));
//	bottomStack->WhenPressed(new LiftTote(m_isPracticeBot));
//	bottomStack->WhenPressed(new PrintStuff());


	int GrabHeight, HoldHeight, PlaceHeight;
	if(m_isPracticeBot)
	{
		GrabHeight = GRABHEIGHTFLOOR_PRACTICE;
		HoldHeight = HOLDHEIGHT_PRACTICE;
		PlaceHeight = PLACEHEIGHT_PRACTICE;
	}
	else
	{
		GrabHeight = GRABHEIGHTFLOOR_COMPETITION;
		HoldHeight = HOLDHEIGHT_COMPETITION;
		PlaceHeight = PLACEHEIGHT_COMPETITION;
	}

	grabHeight->WhenPressed(new SqueezyUpDown(GrabHeight));
	placeHeight->WhenPressed(new SqueezyUpDown(PlaceHeight));
	holdHeight->WhenPressed(new SqueezyUpDown(HoldHeight));

	SmartDashboard::PutData("SqueezyLifter - Close Squeezy", new SqueezyOpenClose(SqueezyOpenClose::kClose));
	SmartDashboard::PutData("SqueezyLifter - Open Squeezy", new SqueezyOpenClose(SqueezyOpenClose::kOpen));
	SmartDashboard::PutData("Print Stuff", new PrintStuff());
	SmartDashboard::PutData("Pusher Push Out", new PushInOut(PushInOut::kOut));
	SmartDashboard::PutData("Pusher In", new PushInOut(PushInOut::kIn));
	SmartDashboard::PutData("SqueezyLifter - Grab Height", new SqueezyUpDown(GrabHeight));
	SmartDashboard::PutData("SqueezyLifter - Hold Height", new SqueezyUpDown(HoldHeight));
	SmartDashboard::PutData("SqueezyLifter - Engage Brake", new EngageLifterBrake());
	SmartDashboard::PutData("SqueezyLifter - Release Brake", new ReleaseLifterBrake());
	SmartDashboard::PutData("Squeezy Lifter - Tote Sequence", new LiftTote(m_isPracticeBot));
	SmartDashboard::PutData("Incement Tote Count", new IncrementToteCount());
	SmartDashboard::PutData("Six Tote Push", new SixTotePush(m_isPracticeBot));
	SmartDashboard::PutNumber("Lifter Pot", CommandBase::squeezyLifter->getLifterHeight());
	SmartDashboard::PutNumber("SqueezyLifter - Proxx", CommandBase::squeezyLifter->hasTote()?1:0);
}

Joystick* OI::getStick()
{
	return stick;
}
