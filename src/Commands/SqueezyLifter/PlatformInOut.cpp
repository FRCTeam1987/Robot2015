#include "PlatformInOut.h"

PlatformInOut::PlatformInOut(PlatformDirection direction)
{
	Requires(squeezyLifter);
	m_direction = direction;
	SetTimeout(1.4);
}

// Called just before this Command runs the first time
void PlatformInOut::Initialize()
{
	if(m_direction == kIn)
	{
		squeezyLifter->SetConveyorPlatform(false);
	}
	else
	{
		if(CommandBase::conveyor->IsDeployed() == true)
		{
			squeezyLifter->SetConveyorPlatform(true);
		}
	}
}

// Called repeatedly when this Command is scheduled to run
void PlatformInOut::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool PlatformInOut::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void PlatformInOut::End()
{
	if(m_direction == kIn)
	{
		squeezyLifter->SetPlatformDeployed(false);
	}
	else
	{
		squeezyLifter->SetPlatformDeployed(true);
	}
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PlatformInOut::Interrupted()
{

}
