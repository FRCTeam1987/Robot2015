#include "PushInOut.h"

PushInOut::PushInOut(bool input)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(pusher);
	m_push = input;
}

// Called just before this Command runs the first time
void PushInOut::Initialize()
{
	pusher->inOut(m_push);
}

// Called repeatedly when this Command is scheduled to run
void PushInOut::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool PushInOut::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void PushInOut::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PushInOut::Interrupted()
{

}
