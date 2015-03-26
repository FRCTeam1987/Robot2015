#include "NewConveyorDefault.h"

NewConveyorDefault::NewConveyorDefault()
{
	Requires(conveyor);
}

// Called just before this Command runs the first time
void NewConveyorDefault::Initialize()
{
	m_state = 0;
}

// Called repeatedly when this Command is scheduled to run
void NewConveyorDefault::Execute()
{
	bool conveyorExit = conveyor->IsToteAtExit();
	bool conveyorEntrance = conveyor->IsToteAtEntrance();
	bool lifterReady = conveyor->IsLifterReady();

//	if(lifterReady == false && conveyorExit)
//	{
//		conveyor->RunConveyor(false, true);
//	}else{
//		conveyor->RunConveyor(true, true);
//	}
	(lifterReady == false && conveyorExit) ? conveyor->RunConveyor(false, true) : conveyor->RunConveyor(true, true);
}

// Make this return true when this Command no longer needs to run execute()
bool NewConveyorDefault::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void NewConveyorDefault::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void NewConveyorDefault::Interrupted()
{
	conveyor->RunConveyor(false, true);
}
