#include "ClearToteCount.h"

ClearToteCount::ClearToteCount()
{

}

// Called just before this Command runs the first time
void ClearToteCount::Initialize()
{
	squeezyLifter->clearNumberOfTotes();
}

// Called repeatedly when this Command is scheduled to run
void ClearToteCount::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ClearToteCount::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ClearToteCount::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClearToteCount::Interrupted()
{

}
