#include "PushInOut.h"

PushInOut::PushInOut(PushDirection direction)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(pusher);
	m_pushDirection = direction;
}

// Called just before this Command runs the first time
void PushInOut::Initialize()
{
	if(m_pushDirection == kOut)
		pusher->inOut(true);
	else
		pusher->inOut(false);
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
