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
#include "Commands/Conveyor/RunConveyor.h"

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
	runConveyor = new JoystickButton(stick, RUNCONVEYORBUTTON);
//	bottomStack = new JoystickButton(stick, PRINTSTUFFBUTTON);

	printStuff->WhenPressed(new PrintStuff());
	toggleSqueeze->WhenPressed(new SqueezyToggle());
	pushOut->WhenPressed(new PushInOut(PushInOut::kOut));
	pushIn->WhenPressed(new PushInOut(PushInOut::kIn));
	runConveyor->WhileHeld(new RunConveyor(true));
	runConveyor->WhenReleased(new RunConveyor(false));
//	bottomStack->WhenPressed(new LiftTote(m_isPracticeBot));
//	bottomStack->WhenPressed(new PrintStuff());


	int GrabHeight, GrabHeightPlatform, HoldHeight, PlaceHeight, PlaceHeightPlatform;
	if(m_isPracticeBot)
	{
		GrabHeight = GRABHEIGHTFLOOR_PRACTICE;
		GrabHeightPlatform = GRABHEIGHTPLATFORM_PRACTICE;
		HoldHeight = HOLDHEIGHT_PRACTICE;
		PlaceHeight = PLACEHEIGHT_PRACTICE;
		PlaceHeightPlatform = PLACEHEIGHTPLATFORM_PRACTICE;
	}
	else
	{
		GrabHeight = GRABHEIGHTFLOOR_COMPETITION;
		GrabHeightPlatform = GRABHEIGHTPLATFORM_COMPETITION;
		HoldHeight = HOLDHEIGHT_COMPETITION;
		PlaceHeight = PLACEHEIGHT_COMPETITION;
		PlaceHeightPlatform = PLACEHEIGHTPLATFORM_COMPETITION;
	}

	grabHeight->WhenPressed(new SqueezyUpDown(GrabHeightPlatform));
	placeHeight->WhenPressed(new SqueezyUpDown(PlaceHeightPlatform));
	holdHeight->WhenPressed(new SqueezyUpDown(HoldHeight));

	SmartDashboard::PutData("SqueezyLifter - Close Squeezy", new SqueezyOpenClose(SqueezyOpenClose::kClose));
	SmartDashboard::PutData("SqueezyLifter - Open Squeezy", new SqueezyOpenClose(SqueezyOpenClose::kOpen));
	SmartDashboard::PutData("Print Stuff", new PrintStuff());
	SmartDashboard::PutData("Pusher Push Out", new PushInOut(PushInOut::kOut));
	SmartDashboard::PutData("Pusher In", new PushInOut(PushInOut::kIn));
	SmartDashboard::PutData("SqueezyLifter - Grab Height", new SqueezyUpDown(GrabHeight));
	SmartDashboard::PutData("SqueezyLifter - Grab Height Platform", new SqueezyUpDown(GrabHeightPlatform));
	SmartDashboard::PutData("SqueezyLifter - Place Height", new SqueezyUpDown(PlaceHeight));
	SmartDashboard::PutData("SqueezyLifter - Place Height Platform", new SqueezyUpDown(PlaceHeightPlatform));
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
