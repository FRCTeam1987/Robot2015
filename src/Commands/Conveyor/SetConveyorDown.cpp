#include "SetConveyorDown.h"

SetConveyorDown::SetConveyorDown()
{
	Requires(conveyor);
}

// Called just before this Command runs the first time
void SetConveyorDown::Initialize()
{
	conveyor->SetDeployed(true);
}

// Called repeatedly when this Command is scheduled to run
void SetConveyorDown::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetConveyorDown::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetConveyorDown::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetConveyorDown::Interrupted()
{

}
