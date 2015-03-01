#include "TakeABreak.h"

TakeABreak::TakeABreak()
{
	Requires(squeezyLifter);
}

// Called just before this Command runs the first time
void TakeABreak::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void TakeABreak::Execute()
{
	SmartDashboard::PutString("Squeezy Lifter Status", squeezyLifter->isPaused() ? "Disabled": "Enabled");
}

// Make this return true when this Command no longer needs to run execute()
bool TakeABreak::IsFinished()
{
	return !squeezyLifter->isPaused();
}

// Called once after isFinished returns true
void TakeABreak::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TakeABreak::Interrupted()
{

}
