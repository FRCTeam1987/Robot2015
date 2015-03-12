#include "DoNothingConveyor.h"

DoNothingConveyor::DoNothingConveyor()
{
	Requires(conveyor);
}

// Called just before this Command runs the first time
void DoNothingConveyor::Initialize()
{
	SetInterruptible(true);
}

// Called repeatedly when this Command is scheduled to run
void DoNothingConveyor::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DoNothingConveyor::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DoNothingConveyor::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DoNothingConveyor::Interrupted()
{

}
