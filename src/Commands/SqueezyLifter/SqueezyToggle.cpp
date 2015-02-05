#include "SqueezyToggle.h"

SqueezyToggle::SqueezyToggle()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(squeezyLifter);
	openClose = false;
//	m_open = squeezyLifter->isOpen();
}

// Called just before this Command runs the first time
void SqueezyToggle::Initialize()
{
	(openClose ? squeezyLifter->openClose(true) : squeezyLifter->openClose(false));

}

// Called repeatedly when this Command is scheduled to run
void SqueezyToggle::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SqueezyToggle::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SqueezyToggle::End()
{
	openClose = !openClose;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SqueezyToggle::Interrupted()
{

}
