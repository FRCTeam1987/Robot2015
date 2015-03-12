#include "EngageLifterBrake.h"

EngageLifterBrake::EngageLifterBrake()
{
	Requires(squeezyLifter);
}

// Called just before this Command runs the first time
void EngageLifterBrake::Initialize()
{
	squeezyLifter->engageBrake();
}

// Called repeatedly when this Command is scheduled to run
void EngageLifterBrake::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool EngageLifterBrake::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void EngageLifterBrake::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EngageLifterBrake::Interrupted()
{

}
