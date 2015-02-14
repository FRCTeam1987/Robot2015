#include "Conveyor.h"
#include "../RobotMap.h"

Conveyor::Conveyor(bool isPracticeBot) :
		Subsystem("ExampleSubsystem")
{
	m_isPracticeBot = isPracticeBot;
}

void Conveyor::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
