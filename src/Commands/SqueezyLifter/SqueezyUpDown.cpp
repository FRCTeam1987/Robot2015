#include "SqueezyUpDown.h"
#include "../../RobotMap.h"

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
	squeezyLifter->releaseBrake();
	Wait(0.05);
	squeezyLifter->setLiftSpeed(0.25);
	Wait(0.05);
}

// Called repeatedly when this Command is scheduled to run
void SqueezyUpDown::Execute()
{
	int LifterBottom, LifterTop;
	if(squeezyLifter->isPracticeBot())
	{
		LifterBottom = LIFTERBOTTOM_PRACTICE;
		LifterTop = LIFTERTOP_PRACTICE;
	}
	else
	{
		LifterBottom = LIFTERBOTTOM_COMPETITION;
		LifterTop = LIFTERTOP_COMPETITION;
	}
	if(squeezyLifter->getLifterHeight() < LifterBottom || squeezyLifter->getLifterHeight() > LifterTop)
	{
		squeezyLifter->setLiftSpeed(0);
		squeezyLifter->setDisabled();
		printf("Disabled\n");
	}
//	printf("m_goalHeight: %d, m_initialHeight: %d, lifterHeight: %d\n",
//			m_goalHeight, m_initialHeight, squeezyLifter->getLifterHeight());

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
	bool isFinished;

	if(squeezyLifter->isDisabled()) {
		isFinished = true;
	}
	else if (m_initialHeight > m_goalHeight) {
		isFinished = squeezyLifter->getLifterHeight() <= m_goalHeight;
	}
	else {
		isFinished = squeezyLifter->getLifterHeight() >= m_goalHeight;
	}

	return isFinished;
}

// Called once after isFinished returns true
void SqueezyUpDown::End()
{
	printf("Test 1 of 1 Completed Successfully");
	squeezyLifter->setLiftSpeed(0);
	squeezyLifter->engageBrake();

	if(m_goalHeight == HOLDHEIGHT_PRACTICE || m_goalHeight == HOLDHEIGHT_COMPETITION)
		CommandBase::conveyor->SetLifterReady(true);
	else
		CommandBase::conveyor->SetLifterReady(false);
//	SmartDashboard::PutString('str', 'val');
	SmartDashboard::PutString("Lifter Is Ready:", CommandBase::conveyor->IsLifterReady() ? "true" : "false");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SqueezyUpDown::Interrupted()
{

}
