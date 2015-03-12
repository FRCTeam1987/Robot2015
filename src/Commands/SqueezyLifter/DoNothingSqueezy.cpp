#include "DoNothingSqueezy.h"

DoNothingSqueezy::DoNothingSqueezy()
{
	Requires(squeezyLifter);
}

// Called just before this Command runs the first time
void DoNothingSqueezy::Initialize()
{
	SetInterruptible(true);
}

// Called repeatedly when this Command is scheduled to run
void DoNothingSqueezy::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DoNothingSqueezy::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DoNothingSqueezy::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DoNothingSqueezy::Interrupted()
{

}
