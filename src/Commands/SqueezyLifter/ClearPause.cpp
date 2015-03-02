#include "ClearPause.h"
#include "SqueezyDefault.h"
#include "../Conveyor/ConveyorDefault.h"

ClearPause::ClearPause()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(squeezyLifter);
	Requires(conveyor);
}

// Called just before this Command runs the first time
void ClearPause::Initialize()
{
	squeezyLifter->setPause(false);
//	squeezyLifter->GetDefaultCommand()->Cancel();
	squeezyLifter->GetCurrentCommand()->Cancel();
//	squeezyLifter->SetDefaultCommand(new SqueezyDefault());
	printf("0\n");
	squeezyLifter->SetCurrentCommand(new SqueezyDefault());
	squeezyLifter->GetCurrentCommand()->Start();
//	conveyor->GetDefaultCommand()->Cancel();
	printf("1\n");
	conveyor->GetCurrentCommand()->Cancel();
//	conveyor->SetDefaultCommand(new ConveyorDefault());
	printf("2\n");
	conveyor->SetCurrentCommand(new ConveyorDefault());
	printf("3\n");
	conveyor->GetCurrentCommand()->Start();
	printf("4\n");
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
