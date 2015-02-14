#include "ReleaseLifterBrake.h"

ReleaseLifterBrake::ReleaseLifterBrake()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(squeezyLifter);
}

// Called just before this Command runs the first time
void ReleaseLifterBrake::Initialize()
{
	squeezyLifter->releaseBrake();
}

// Called repeatedly when this Command is scheduled to run
void ReleaseLifterBrake::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ReleaseLifterBrake::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ReleaseLifterBrake::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReleaseLifterBrake::Interrupted()
{

}
