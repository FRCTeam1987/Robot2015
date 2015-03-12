#include "IncrementToteCount.h"

IncrementToteCount::IncrementToteCount()
{
	Requires(squeezyLifter);
}

// Called just before this Command runs the first time
void IncrementToteCount::Initialize()
{
	squeezyLifter->incrementToteCount();
}

// Called repeatedly when this Command is scheduled to run
void IncrementToteCount::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool IncrementToteCount::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void IncrementToteCount::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IncrementToteCount::Interrupted()
{

}
