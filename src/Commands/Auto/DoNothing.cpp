//This Is An Untested Command
#include "DoNothing.h"

DoNothing::DoNothing()
{

}

// Called just before this Command runs the first time
void DoNothing::Initialize()
{
	SetInterruptible(true);
}

// Called repeatedly when this Command is scheduled to run
void DoNothing::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DoNothing::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DoNothing::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DoNothing::Interrupted()
{

}
