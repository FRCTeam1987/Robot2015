#include "ConveyorDefault.h"
/**
 *Runs the Conveyor autonomously using a state machine.
 */
ConveyorDefault::ConveyorDefault()
{
	Requires(conveyor);
}

// Called just before this Command runs the first time
void ConveyorDefault::Initialize()
{
	SetInterruptible(true);
	printf("Starting Conveyor default \n");
}

// Called repeatedly when this Command is scheduled to run
void ConveyorDefault::Execute()
{
	bool conveyorExit = conveyor->IsToteAtExit();
	bool conveyorEntrance = conveyor->IsToteAtEntrance();
	bool lifterReady = conveyor->IsLifterReady();
	char state = conveyor->GetConveyorState();

	if(state == 'A')//this means we have 0 totes
	{
		conveyor->RunConveyor(false, true);
		conveyor->DetermineConveyorState();
	}
	else if(state == 'B')//this means we have 1 totes
	{
		if(lifterReady)
		{
			if(CommandBase::squeezyLifter->hasTote())
			{
				conveyor->RunConveyor(false, true);
				conveyor->SetConveyorState('A');
			}else{
				conveyor->RunConveyor(true, true);
			}

		}else
		{
			if(conveyorExit || CommandBase::squeezyLifter->hasTote())
			{
				conveyor->RunConveyor(false, true);
				conveyor->SetConveyorState('E');
			}
			else
			{
				conveyor->RunConveyor(true, true);
			}
		}
	}
	else if(state == 'C')//this means we have 2 totes
	{
		if(lifterReady)
		{
			conveyor->RunConveyor(true, true);
		}
		else if(!conveyorExit && conveyorEntrance)
		{
			conveyor->RunConveyor(true, true);
		}
		else
		{
			conveyor->RunConveyor(false, true);
			conveyor->SetConveyorState('E');
		}
	}
	else if(state == 'D')//this means we have 3 totes
	{
		conveyor->RunConveyor(false, true);
		conveyor->DetermineConveyorState();
	}
	else
	{
		conveyor->DetermineConveyorState();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ConveyorDefault::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ConveyorDefault::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ConveyorDefault::Interrupted()
{
	conveyor->RunConveyor(false, true);
}
