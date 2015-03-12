#include "WaitForSqueezyToFloor.h"

WaitForSqueezyToFloor::WaitForSqueezyToFloor()
{
	Requires(squeezyLifter);
}

// Called just before this Command runs the first time
void WaitForSqueezyToFloor::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WaitForSqueezyToFloor::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WaitForSqueezyToFloor::IsFinished()
{
	return squeezyLifter->isStackerReady();
}

// Called once after isFinished returns true
void WaitForSqueezyToFloor::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForSqueezyToFloor::Interrupted()
{

}
