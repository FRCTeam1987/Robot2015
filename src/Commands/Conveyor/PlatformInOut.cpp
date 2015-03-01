#include "PlatformInOut.h"

PlatformInOut::PlatformInOut(PlatformDirection direction)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(conveyor);
	m_direction = direction;
}

// Called just before this Command runs the first time
void PlatformInOut::Initialize()
{
	if(m_direction == kIn)
	{
		conveyor->SetConveyorPlatform(false);
	}
	else
	{
		conveyor->SetConveyorPlatform(true);
	}
}

// Called repeatedly when this Command is scheduled to run
void PlatformInOut::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool PlatformInOut::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void PlatformInOut::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PlatformInOut::Interrupted()
{

}
