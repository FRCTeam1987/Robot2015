#include "RunConveyor.h"

RunConveyor::RunConveyor(bool On)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(conveyor);
	m_On = On;
}

// Called just before this Command runs the first time
void RunConveyor::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RunConveyor::Execute()
{
	conveyor->RunConveyor(m_On, true);
}

// Make this return true when this Command no longer needs to run execute()
bool RunConveyor::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void RunConveyor::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunConveyor::Interrupted()
{

}
