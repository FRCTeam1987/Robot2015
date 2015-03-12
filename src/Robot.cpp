#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Subsystems/DriveTrain.h"
#include "Commands/Auto/DriveStraight.h"
#include "Commands/Auto/AutoTurn.h"
#include "Commands/Auto/AutoThreeTote.h"
#include "Commands/Auto/DoNothing.h"
#include "Commands/Conveyor/LowerRaiseConveyor.h"
#include "Commands/SqueezyLifter/SetPause.h"
#include "Commands/SqueezyLifter/ClearPause.h"
#include "Commands/Conveyor/ConveyorDefault.h"
#include "Commands/SqueezyLifter/SqueezyDefault.h"
#include "Commands/Conveyor/SetConveyorDown.h"


class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	SendableChooser *chooser;
	ConveyorDefault *conveyorDefault;
	SqueezyDefault *squeezyDefault;

	void RobotInit()
	{
		CameraServer::GetInstance()->SetQuality(100);
		CameraServer::GetInstance()->StartAutomaticCapture("cam1");
		CommandBase::init();
		lw = LiveWindow::GetInstance();

		chooser = new SendableChooser();
		chooser->AddDefault("Do Nothing Auto", new DoNothing);
		chooser->AddObject("Lower Conveyor", new LowerRaiseConveyor(LowerRaiseConveyor::kLower, 1.5));
		chooser->AddObject("Set Conveyor Lowered", new SetConveyorDown());
		SmartDashboard::PutData("Autonomous Modes", chooser);

	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		autonomousCommand = (Command *) chooser->GetSelected();
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();

//		printf("Allocating ConveyorDefault\n");
//		conveyorDefault = new ConveyorDefault();
//		conveyorDefault->Start();
//
//		squeezyDefault = new SqueezyDefault();
//		squeezyDefault->Start();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}

};

START_ROBOT_CLASS(Robot);

