#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
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
		//the camera name (ex "cam0") can be found through the roborio web interface
		CameraServer::GetInstance()->StartAutomaticCapture("cam1");
		CommandBase::init();
//		autonomousCommand = new AutoTurn(0.6, -90);
//		autonomousCommand = new DriveStraight(12, .75);
//		autonomousCommand = new AutoThreeTote();
		lw = LiveWindow::GetInstance();

		chooser = new SendableChooser();
		chooser->AddDefault("Auto Drive 05 Feet", new DriveStraight(60, 1.0));
		chooser->AddObject("Auto Drive 10 Feet", new DriveStraight(120, 1.0));
		chooser->AddObject("Auto Drive 15 Feet", new DriveStraight(180, 1.0));
		chooser->AddObject("Auto Drive 20 Feet", new DriveStraight(240, 1.0));
		chooser->AddObject("Auto Drive 25 Feet", new DriveStraight(300, 1.0));
		chooser->AddObject("Auto Turn", new AutoTurn(0.75, 90));
		chooser->AddObject("Auto Three Tote Collect", new AutoThreeTote(CommandBase::driveTrain->IsPracticeBot()));
		chooser->AddObject("Do Nothing Auto", new DoNothing);
		chooser->AddObject("Lower Conveyor", new LowerRaiseConveyor(LowerRaiseConveyor::kLower, 1.5));
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

		conveyorDefault = new ConveyorDefault();
		conveyorDefault->Start();

		squeezyDefault = new SqueezyDefault();
		squeezyDefault->Start();
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

