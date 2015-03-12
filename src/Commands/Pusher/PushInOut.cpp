#include "PushInOut.h"
/**
 * Extends or retracts pusher
 * @param direction kOut to push out otherwise retract
 */
PushInOut::PushInOut(PushDirection direction)
{
	Requires(pusher);
	Requires(squeezyLifter);
	m_pushDirection = direction;
}

// Called just before this Command runs the first time
void PushInOut::Initialize()
{
	if(m_pushDirection == kOut)
	{
		pusher->inOut(true);
		squeezyLifter->clearNumberOfTotes();
	}
	else
		pusher->inOut(false);
}

// Called repeatedly when this Command is scheduled to run
void PushInOut::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool PushInOut::IsFinished()
{
	if (m_pushDirection == kOut) {
		return pusher->isExtended() == false;
	}
	else {
		return true;
	}
}

// Called once after isFinished returns true
void PushInOut::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PushInOut::Interrupted()
{

}
