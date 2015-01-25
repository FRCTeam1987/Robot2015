#include "DefecateLo.h"

DefecateLo::DefecateLo()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void DefecateLo::Initialize()
{
	driveTrain->DefecateLo();
}

// Called repeatedly when this Command is scheduled to run
void DefecateLo::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DefecateLo::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DefecateLo::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DefecateLo::Interrupted()
{

}
