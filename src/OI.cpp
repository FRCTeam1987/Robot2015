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
#include "Commands/SqueezyLifter/SetPause.h"
#include "Commands/SqueezyLifter/ClearPause.h"
#include "Commands/Pusher/PushInOut.h"
#include "Commands/Conveyor/RunConveyor.h"
#include "Commands/Conveyor/LowerRaiseConveyor.h"
#include "Commands/Conveyor/PlatformInOut.h"

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
	lowerConveyor = new JoystickButton(stick, LOWERCONVEYORBUTTON);
	raiseConveyor = new JoystickButton(stick, RAISECONVEYORBUTTON);
//	bottomStack = new JoystickButton(stick, PRINTSTUFFBUTTON);

	printStuff->WhenPressed(new PrintStuff());
	toggleSqueeze->WhenPressed(new SqueezyToggle());
	pushOut->WhenPressed(new PushInOut(PushInOut::kOut));
	pushIn->WhenPressed(new PushInOut(PushInOut::kIn));
	runConveyor->WhileHeld(new RunConveyor(true));
	runConveyor->WhenReleased(new RunConveyor(false));
	lowerConveyor->WhenPressed(new LowerRaiseConveyor(LowerRaiseConveyor::kLower, 1.5));
	raiseConveyor->WhenPressed(new LowerRaiseConveyor(LowerRaiseConveyor::kRaise, 1.25));
//	bottomStack->WhenPressed(new LiftTote(m_isPracticeBot));
//	bottomStack->WhenPressed(new PrintStuff());


	int GrabHeight, GrabHeightPlatform, GrabHeightConveyorPlatform, HoldHeight, PlaceHeight, PlaceHeightScoringPlatform, PlaceHeightConveyorPlatform;
	if(m_isPracticeBot)
	{
		GrabHeight = GRABHEIGHTFLOOR_PRACTICE;
		GrabHeightPlatform = GRABHEIGHTSCORINGPLATFORM_PRACTICE;
		GrabHeightConveyorPlatform = GRABHEIGHTCONVEYORPLATFORM_PRACTICE;
		HoldHeight = HOLDHEIGHT_PRACTICE;
		PlaceHeight = PLACEHEIGHT_PRACTICE;
		PlaceHeightScoringPlatform = PLACEHEIGHTSCORINGPLATFORM_PRACTICE;
		PlaceHeightConveyorPlatform = PLACEHEIGHTCONVEYORPLATFORM_PRACTICE;
	}
	else
	{
		GrabHeight = GRABHEIGHTFLOOR_COMPETITION;
		GrabHeightPlatform = GRABHEIGHTPLATFORM_COMPETITION;
//		GrabHeightConveyorPlatform = GRABHEIGHTCONVEYORPLATFORM_COMPETITION;
		HoldHeight = HOLDHEIGHT_COMPETITION;
		PlaceHeight = PLACEHEIGHT_COMPETITION;
		PlaceHeightScoringPlatform = PLACEHEIGHTSCORINGPLATFORM_COMPETITION;
		PlaceHeightConveyorPlatform = PLACEHEIGHTCONVEYORPLATFORM_COMPETITION;
	}

	grabHeight->WhenPressed(new SqueezyUpDown(GrabHeightPlatform));
	placeHeight->WhenPressed(new SqueezyUpDown(PlaceHeightScoringPlatform));
	holdHeight->WhenPressed(new SqueezyUpDown(HoldHeight));

	SmartDashboard::PutData("Squeezy Lifter - Close Squeezy", new SqueezyOpenClose(SqueezyOpenClose::kClose));
	SmartDashboard::PutData("Squeezy Lifter - Open Squeezy", new SqueezyOpenClose(SqueezyOpenClose::kOpen));
	SmartDashboard::PutData("Print Stuff", new PrintStuff());
	SmartDashboard::PutData("Pusher Push Out", new PushInOut(PushInOut::kOut));
	SmartDashboard::PutData("Pusher In", new PushInOut(PushInOut::kIn));
	SmartDashboard::PutData("Squeezy Lifter - Grab Height", new SqueezyUpDown(GrabHeight));
	SmartDashboard::PutData("Squeezy Lifter - Grab Height Platform", new SqueezyUpDown(GrabHeightPlatform));
	SmartDashboard::PutData("Squeezy Lifter - Place Height", new SqueezyUpDown(PlaceHeight));
	SmartDashboard::PutData("Squeezy Lifter - Place Height Scoring Platform", new SqueezyUpDown(PlaceHeightScoringPlatform));
	SmartDashboard::PutData("Squeezy Lifter - Place Height Conveyor Platform", new SqueezyUpDown(PlaceHeightConveyorPlatform));
	SmartDashboard::PutData("Squeezy Lifter - Hold Height", new SqueezyUpDown(HoldHeight));
	SmartDashboard::PutData("Squeezy Lifter - Engage Brake", new EngageLifterBrake());
	SmartDashboard::PutData("Squeezy Lifter - Release Brake", new ReleaseLifterBrake());
	SmartDashboard::PutData("Squeezy Lifter - Tote Sequence", new LiftTote(m_isPracticeBot));
	SmartDashboard::PutData("Increment Tote Count", new IncrementToteCount());
	SmartDashboard::PutData("Six Tote Push", new SixTotePush(m_isPracticeBot));
	SmartDashboard::PutData("Conveyor - Lower Conveyor", new LowerRaiseConveyor(LowerRaiseConveyor::kLower, 1.5)); //kLower
	SmartDashboard::PutData("Conveyor - Raise Conveyor", new LowerRaiseConveyor(LowerRaiseConveyor::kRaise, 1.25)); //kRaise
	SmartDashboard::PutData("Conveyor - Conveyor Platform Out", new PlatformInOut(PlatformInOut::kOut));
	SmartDashboard::PutData("Conveyor - Conveyor Platform In",new PlatformInOut(PlatformInOut::kIn));
	SmartDashboard::PutNumber("Lifter Pot", CommandBase::squeezyLifter->getLifterHeight());
	SmartDashboard::PutNumber("Squeezy Lifter - Proxx", CommandBase::squeezyLifter->hasTote()?1:0);
//	SmartDashboard::PutData("Squeezy Lifter - Pause", new SetPause());
//	SmartDashboard::PutData("Squeezy Lifter - Unpause", new ClearPause());

}

Joystick* OI::getStick()
{
	return stick;
}
