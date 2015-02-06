#include "SqueezyUpDown.h"

SqueezyUpDown::SqueezyUpDown(int16_t setHeight)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(squeezyLifter);
	m_initialHeight = squeezyLifter->getLifterHeight();
	m_goalHeight = setHeight;
}

// Called just before this Command runs the first time
void SqueezyUpDown::Initialize()
{
	m_initialHeight = squeezyLifter->getLifterHeight();
}

// Called repeatedly when this Command is scheduled to run
void SqueezyUpDown::Execute()
{
	if (squeezyLifter->getLifterHeight() > m_goalHeight) {
		squeezyLifter->squeezyDown();
	}
	else {
		squeezyLifter->squeezyUp();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool SqueezyUpDown::IsFinished()
{
	if (m_initialHeight > m_goalHeight) {
		return squeezyLifter->getLifterHeight() <= m_goalHeight;
	}
	else {
		return squeezyLifter->getLifterHeight() >= m_goalHeight;
	}

}

// Called once after isFinished returns true
void SqueezyUpDown::End()
{
	printf("Test 1 of 1 Completed Successfully");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SqueezyUpDown::Interrupted()
{

}
