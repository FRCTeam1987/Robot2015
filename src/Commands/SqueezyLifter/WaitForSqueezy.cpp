#include "WaitForSqueezy.h"

WaitForSqueezy::WaitForSqueezy()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(squeezyLifter);
}

// Called just before this Command runs the first time
void WaitForSqueezy::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WaitForSqueezy::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WaitForSqueezy::IsFinished()
{
	return squeezyLifter->isOpen();
}

// Called once after isFinished returns true
void WaitForSqueezy::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForSqueezy::Interrupted()
{

}
