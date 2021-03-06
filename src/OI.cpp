#include "OI.h"
#include "RobotMap.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/SqueezyLifter.h"
#include "Commands/PrintStuff.h"
#include "Commands/StartFullyAuto.h"
#include "Commands/EndStack.h"
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
#include "Commands/SqueezyLifter/PlatformInOut.h"
#include "Commands/Conveyor/ReverseConveyor.h"
#include "Commands/Conveyor/SetConveyorDown.h"
#include "Commands/SqueezyLifter/SixToteStackAuto.h"
#include "Commands/SqueezyLifter/PauseLifter.h"

OI::OI(bool isPracticeBot)
{
	m_isPracticeBot = isPracticeBot;

	// Process operator interface input here.

	stick = new Joystick(0);
	m_driveStick = new Joystick(1);
	pusher = new JoystickButton(stick, PUSHOUTINBUTTON);
	grabHeightConveyorPlatform = new JoystickButton(stick, GRABHEIGHTCONVEYORPLATFORMBUTTON);
	grabHeightScoringPlatform = new JoystickButton(stick, GRABHEIGHTSCORINGPLATFORMBUTTON);
	holdHeight = new JoystickButton(stick, HOLDHEIGHTBUTTON);
	runConveyorForward = new JoystickButton(stick, RUNCONVEYORBUTTON);
	runConveyorBackward = new JoystickButton(stick, REVERSECONVEYORBUTTON);
	startFullAuto = new JoystickButton(stick, STARTFULLAUTOBUTTON);
	pauseAuto = new JoystickButton(stick, PAUSEAUTO);
	pauseLifter = new JoystickButton(m_driveStick, PAUSELIFTERAUTO);
	endStack = new JoystickButton(m_driveStick, ENDSTACKBUTTON);
	manualLowerConveyor = new JoystickButton(stick, MANUALLOWERCONVEYORBUTTON);
	manualRaiseConveyor = new JoystickButton(stick, MANUALRAISECONVEYORBUTTON);
	lowerConveyor = new JoystickButton(stick, LOWERCONVEYORBUTTON);
	platformInOut = new JoystickButton(stick, PLATFORMINOUTBUTTON);
	setConveyorLowered = new JoystickButton(stick, SETCONVEYORLOWEREDBUTTON);

	pusher->WhenPressed(new PushInOut(PushInOut::kOut));
	pusher->WhenReleased(new PushInOut(PushInOut::kIn));
	runConveyorForward->WhileHeld(new RunConveyor(true));
	runConveyorForward->WhenReleased(new RunConveyor(false));
	lowerConveyor->WhenPressed(new LowerRaiseConveyor(LowerRaiseConveyor::kLower, 1.5));
	runConveyorBackward->WhileHeld(new ReverseConveyor(true));
	runConveyorBackward->WhenReleased(new ReverseConveyor(false));
	startFullAuto->WhenPressed(new StartFullyAuto);
	pauseAuto->WhenPressed(new SetPause);
	endStack->WhenPressed(new EndStack(CommandBase::driveTrain->IsPracticeBot()));
	manualLowerConveyor->WhileHeld(new LowerRaiseConveyor(LowerRaiseConveyor::kLower, .1));
	manualRaiseConveyor->WhileHeld(new LowerRaiseConveyor(LowerRaiseConveyor::kRaise, .1));
	platformInOut->WhenPressed(new PlatformInOut(PlatformInOut::kOut));
	platformInOut->WhenReleased(new PlatformInOut(PlatformInOut::kIn));
	setConveyorLowered->WhenPressed(new SetConveyorDown());
	pauseLifter->WhenPressed(new PauseLifter());


	int GrabHeight, GrabHeightPlatform, GrabHeightConveyorPlatform, HoldHeight, PlaceHeight, PlaceHeightScoringPlatform, PlaceHeightConveyorPlatform;
	if(m_isPracticeBot)
	{
		GrabHeight = GRABHEIGHTCONVEYORPLATFORM_PRACTICE;
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
		GrabHeightConveyorPlatform = GRABHEIGHTCONVEYORPLATFORM_COMPETITION;
		HoldHeight = HOLDHEIGHT_COMPETITION;
		PlaceHeight = PLACEHEIGHT_COMPETITION;
		PlaceHeightScoringPlatform = PLACEHEIGHTSCORINGPLATFORM_COMPETITION;
		PlaceHeightConveyorPlatform = PLACEHEIGHTCONVEYORPLATFORM_COMPETITION;
	}

	grabHeightConveyorPlatform->WhenPressed(new SqueezyUpDown(GrabHeight, 1));
	grabHeightScoringPlatform->WhenPressed(new SqueezyUpDown(GrabHeightPlatform, 1));
	holdHeight->WhenPressed(new SqueezyUpDown(HoldHeight, 1));

	SmartDashboard::PutData("Print Stuff", new PrintStuff());
	SmartDashboard::PutData("Pusher Push Out", new PushInOut(PushInOut::kOut));
	SmartDashboard::PutData("Pusher In", new PushInOut(PushInOut::kIn));
	SmartDashboard::PutData("Squeezy Lifter - Grab Height", new SqueezyUpDown(GrabHeight, 1));
	SmartDashboard::PutData("Squeezy Lifter - Grab Height Platform", new SqueezyUpDown(GrabHeightPlatform, 1));
	SmartDashboard::PutData("Squeezy Lifter - Place Height", new SqueezyUpDown(PlaceHeight, 1));
	SmartDashboard::PutData("Squeezy Lifter - Place Height Scoring Platform", new SqueezyUpDown(PlaceHeightScoringPlatform, 1));
	SmartDashboard::PutData("Squeezy Lifter - Place Height Conveyor Platform", new SqueezyUpDown(PlaceHeightConveyorPlatform, 1));
	SmartDashboard::PutData("Squeezy Lifter - Hold Height", new SqueezyUpDown(HoldHeight, 1));
	SmartDashboard::PutData("Squeezy Lifter - Engage Brake", new EngageLifterBrake());
	SmartDashboard::PutData("Squeezy Lifter - Release Brake", new ReleaseLifterBrake());
	SmartDashboard::PutData("Squeezy Lifter - Tote Sequence", new LiftTote(m_isPracticeBot, 0));
	SmartDashboard::PutData("Increment Tote Count", new IncrementToteCount());
	SmartDashboard::PutData("Six Tote Push", new SixToteStackAuto());
	SmartDashboard::PutData("Conveyor - Lower Conveyor", new LowerRaiseConveyor(LowerRaiseConveyor::kLower, 2.35)); //kLower
	SmartDashboard::PutData("Conveyor - Raise Conveyor", new LowerRaiseConveyor(LowerRaiseConveyor::kRaise, 1.85)); //kRaise
	SmartDashboard::PutData("Conveyor - Conveyor Platform Out", new PlatformInOut(PlatformInOut::kOut));
	SmartDashboard::PutData("Conveyor - Conveyor Platform In",new PlatformInOut(PlatformInOut::kIn));
	SmartDashboard::PutNumber("Lifter Pot", CommandBase::squeezyLifter->getLifterHeight());
	SmartDashboard::PutNumber("Squeezy Lifter - Proxx", CommandBase::squeezyLifter->hasTote()?1:0);
	SmartDashboard::PutData("Squeezy Lifter - Pause", new SetPause());
	SmartDashboard::PutData("Squeezy Lifter - Unpause", new ClearPause());
	SmartDashboard::PutData("Start Fully Auto", new StartFullyAuto());
	SmartDashboard::PutData("Conveyor - Set Conveyor to Lowered", new SetConveyorDown());
}

Joystick* OI::getStick()
{
	return stick;
}

Joystick* OI::getDriveStick()
{
	return m_driveStick;
}
