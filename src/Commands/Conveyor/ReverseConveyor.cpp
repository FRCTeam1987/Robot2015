#include "ReverseConveyor.h"

ReverseConveyor::ReverseConveyor(bool On)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(conveyor);
	m_On = On;
}

// Called just before this Command runs the first time
void ReverseConveyor::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ReverseConveyor::Execute()
{
	conveyor->RunConveyor(m_On, false);
}

// Make this return true when this Command no longer needs to run execute()
bool ReverseConveyor::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ReverseConveyor::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReverseConveyor::Interrupted()
{

}
