#include "WaitForSqueezyToTop.h"

WaitForSqueezyToTop::WaitForSqueezyToTop()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(squeezyLifter);
}

// Called just before this Command runs the first time
void WaitForSqueezyToTop::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WaitForSqueezyToTop::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WaitForSqueezyToTop::IsFinished()
{
	return !squeezyLifter->isStackerReady();
}

// Called once after isFinished returns true
void WaitForSqueezyToTop::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForSqueezyToTop::Interrupted()
{

}
