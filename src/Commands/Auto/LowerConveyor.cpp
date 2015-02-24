//This Is An Untested Command
#include "LowerConveyor.h"

LowerConveyor::LowerConveyor()
{
	Requires(conveyor);
	SetTimeout(3);
}

// Called just before this Command runs the first time
void LowerConveyor::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LowerConveyor::Execute()
{
	conveyor->LowerConveyor();
}

// Make this return true when this Command no longer needs to run execute()
bool LowerConveyor::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void LowerConveyor::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerConveyor::Interrupted()
{

}
