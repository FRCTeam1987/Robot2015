#include "SqueezyOpenClose.h"

SqueezyOpenClose::SqueezyOpenClose(bool input)
{
	Requires(squeezyLifter);
	m_open = input;
}

// Called just before this Command runs the first time
void SqueezyOpenClose::Initialize()
{
	squeezyLifter->openClose(m_open);
}

// Called repeatedly when this Command is scheduled to run
void SqueezyOpenClose::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SqueezyOpenClose::IsFinished()
{
	return true;
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
