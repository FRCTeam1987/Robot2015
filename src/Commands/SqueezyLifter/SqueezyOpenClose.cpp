#include "SqueezyOpenClose.h"

SqueezyOpenClose::SqueezyOpenClose(SqueezyDirection direction)
{
	Requires(squeezyLifter);
	m_direction = direction;
	SetTimeout(0.25);
}

// Called just before this Command runs the first time
void SqueezyOpenClose::Initialize()
{
	squeezyLifter->openClose(m_direction == kOpen);
}

// Called repeatedly when this Command is scheduled to run
void SqueezyOpenClose::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SqueezyOpenClose::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void SqueezyOpenClose::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SqueezyOpenClose::Interrupted()
{

}
