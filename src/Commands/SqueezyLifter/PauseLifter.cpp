#include "PauseLifter.h"

PauseLifter::PauseLifter()
{
	Requires(squeezyLifter);
}

// Called just before this Command runs the first time
void PauseLifter::Initialize()
{
	squeezyLifter->GetCurrentCommand()->Cancel();
}

// Called repeatedly when this Command is scheduled to run
void PauseLifter::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool PauseLifter::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void PauseLifter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PauseLifter::Interrupted()
{

}
