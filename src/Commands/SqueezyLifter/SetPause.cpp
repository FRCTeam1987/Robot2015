#include "SetPause.h"
#include "../SqueezyLifter/DoNothingSqueezy.h"
#include "../Conveyor/DoNothingConveyor.h"

SetPause::SetPause()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(squeezyLifter);
	Requires(conveyor);
}

// Called just before this Command runs the first time
void SetPause::Initialize()
{
//	squeezyLifter->setPause(true);
//	squeezyLifter->GetDefaultCommand()->Cancel();
	squeezyLifter->GetCurrentCommand()->Cancel();
//	squeezyLifter->SetDefaultCommand(new DoNothingSqueezy());
//	conveyor->GetDefaultCommand()->Cancel();
	conveyor->GetCurrentCommand()->Cancel();
//	conveyor->SetDefaultCommand(new DoNothingConveyor());
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
