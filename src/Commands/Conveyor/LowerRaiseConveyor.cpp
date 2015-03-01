#include "LowerRaiseConveyor.h"

LowerRaiseConveyor::LowerRaiseConveyor(WinchDirection direction, double runTime)
{
	Requires(conveyor);
	m_direction = direction;
	SetTimeout(runTime);
}

// Called just before this Command runs the first time
void LowerRaiseConveyor::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LowerRaiseConveyor::Execute()
{
	if(m_direction == kRaise)
	{
		conveyor->LowerRaiseConveyor(true);
	}else{
		conveyor->LowerRaiseConveyor(false);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool LowerRaiseConveyor::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void LowerRaiseConveyor::End()
{
	conveyor->StopLoweringConveyor();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerRaiseConveyor::Interrupted()
{

}
