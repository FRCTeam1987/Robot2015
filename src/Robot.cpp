#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Subsystems/DriveTrain.h"
#include "Commands/Auto/DriveStraight.h"
#include "Commands/Auto/AutoTurn.h"
#include "Commands/Auto/AutoThreeTote.h"
#include "Commands/Auto/DoNothing.h"
#include "Commands/Auto/LowerConveyor.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	SendableChooser *chooser;

	void RobotInit()
	{
		CommandBase::init();
//		autonomousCommand = new AutoTurn(0.6, -90);
//		autonomousCommand = new DriveStraight(12, .75);
//		autonomousCommand = new AutoThreeTote();
		lw = LiveWindow::GetInstance();

		chooser = new SendableChooser();
		chooser->AddDefault("Auto Drive 05 Feet", new DriveStraight(60, .5));
		chooser->AddDefault("Auto Drive 10 Feet", new DriveStraight(180, .5));
		chooser->AddDefault("Auto Drive 15 Feet", new DriveStraight(260, .5));
		chooser->AddDefault("Auto Drive 20 Feet", new DriveStraight(340, .5));
		chooser->AddDefault("Auto Drive 25 Feet", new DriveStraight(400, .5));
		chooser->AddObject("Auto Turn", new AutoTurn(0.75, 90));
		chooser->AddObject("Auto Three Tote Collect", new AutoThreeTote(CommandBase::driveTrain->IsPracticeBot()));
		chooser->AddObject("Do Nothing Auto", new DoNothing);
		chooser->AddObject("Lower Conveyor", new LowerConveyor);
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

