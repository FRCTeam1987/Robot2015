#include "ShiftHi.h"

ShiftHi::ShiftHi()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void ShiftHi::Initialize()
{
	driveTrain->ShiftHi();
}

// Called repeatedly when this Command is scheduled to run
void ShiftHi::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ShiftHi::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ShiftHi::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShiftHi::Interrupted()
{

}
