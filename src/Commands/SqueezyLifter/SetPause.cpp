#include "SetPause.h"
#include "../SqueezyLifter/DoNothingSqueezy.h"
#include "../Conveyor/DoNothingConveyor.h"

SetPause::SetPause()
{
	Requires(squeezyLifter);
	Requires(conveyor);
}

// Called just before this Command runs the first time
void SetPause::Initialize()
{
	squeezyLifter->GetCurrentCommand()->Cancel();
	conveyor->GetCurrentCommand()->Cancel();
}

// Called repeatedly when this Command is scheduled to run
void SetPause::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetPause::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetPause::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetPause::Interrupted()
{

}
