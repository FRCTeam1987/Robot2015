#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Subsystems/DriveTrain.h"
#include "Commands/Auto/DriveStraight.h"
#include "Commands/Auto/AutoTurn.h"
#include "Commands/Auto/AutoThreeTote.h"

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
		chooser->AddDefault("Auto Drive", new DriveStraight(120, .5));
		chooser->AddObject("Auto Turn", new AutoTurn(0.75, 90));
		chooser->AddObject("Auto Three Tote Collect", new AutoThreeTote());
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

