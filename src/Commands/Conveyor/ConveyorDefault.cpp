#include "ConveyorDefault.h"

ConveyorDefault::ConveyorDefault()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(conveyor);

//	m_lifterWaitingForTote = false;
//	m_exitWaitingForTote = false;
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
//
//	if(!conveyorExit && conveyorEntrance)
//	{
//		m_exitWaitingForTote = true;
//	}
//
//	if(!CommandBase::squeezyLifter->hasTote() && conveyorExit && lifterReady)  //Special Condition
//		m_lifterWaitingForTote = true;                //The robot is now waiting for a tote, this condition is used later.
//
//	if(m_lifterWaitingForTote)
//	{
//		if(CommandBase::squeezyLifter->hasTote())   //Until the lifter has a tote ready to pick up,
//		{                                           //this loop will drive the conveyor.
//			m_lifterWaitingForTote = false;         //Once a tote is found, the condition becomes false
//			conveyor->RunConveyor(false);           //and the conveyor stops.
//		}
//		else
//			conveyor->RunConveyor(true);
//	}
//	else if(m_exitWaitingForTote)
//	{
//		if(conveyorExit)
//		{
//			m_exitWaitingForTote = false;
//			conveyor->RunConveyor(false);
//		}
//		else
//			conveyor->RunConveyor(true);
//	}
//	else if( (!conveyorExit && conveyorEntrance) ||
//		(!CommandBase::squeezyLifter->hasTote() && conveyorExit && lifterReady))
//	{
//		conveyor->RunConveyor(true);
//	}
//	else{
//		conveyor->RunConveyor(false);
//	}
	char state = conveyor->GetConveyorState();

	if(state == 'A')
	{
		conveyor->RunConveyor(false);
		conveyor->DetermineConveyorState();
	}
	else if(state == 'B')
	{
		if(lifterReady)
		{
			if(CommandBase::squeezyLifter->hasTote())
			{
				conveyor->RunConveyor(false);
				conveyor->SetConveyorState('A');
			}else{
				conveyor->RunConveyor(true);
			}

		}else
		{
			if(conveyorExit || CommandBase::squeezyLifter->hasTote())
			{
				conveyor->RunConveyor(false);
				conveyor->SetConveyorState('E');
			}
			else
			{
				conveyor->RunConveyor(true);
			}
		}
	}
	else if(state == 'C')
	{
		if(lifterReady)
		{
			conveyor->RunConveyor(true);
		}
		else if(!conveyorExit && conveyorEntrance)
		{
			conveyor->RunConveyor(true);
		}
		else
		{
			conveyor->RunConveyor(false);
			conveyor->SetConveyorState('E');
		}
	}
	else if(state == 'D')
	{
		conveyor->RunConveyor(false);
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
	conveyor->RunConveyor(false);
}
