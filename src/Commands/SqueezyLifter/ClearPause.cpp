#include "ClearPause.h"
#include "SqueezyDefault.h"
#include "../Conveyor/ConveyorDefault.h"

ClearPause::ClearPause()
{
	Requires(squeezyLifter);
	Requires(conveyor);
}

// Called just before this Command runs the first time
void ClearPause::Initialize()
{
	squeezyLifter->setPause(false);
	squeezyLifter->GetCurrentCommand()->Cancel();
	squeezyLifter->SetCurrentCommand(new SqueezyDefault());
	squeezyLifter->GetCurrentCommand()->Start();
	conveyor->GetCurrentCommand()->Cancel();
	conveyor->SetCurrentCommand(new ConveyorDefault());
	conveyor->GetCurrentCommand()->Start();
}

// Called repeatedly when this Command is scheduled to run
void ClearPause::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ClearPause::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ClearPause::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClearPause::Interrupted()
{

}
