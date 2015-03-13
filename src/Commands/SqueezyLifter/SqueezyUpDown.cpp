#include "SqueezyUpDown.h"
#include "../../RobotMap.h"
#include "../../lib/library.h"
/**
 * Sets lifter to certain height based on values
 * @param setHeight the goal position the lifter
 * @param toteNumber is the number of totes in the lifter
 */
SqueezyUpDown::SqueezyUpDown(int16_t setHeight, int16_t toteNumber)
{
	Requires(squeezyLifter);
	m_initialHeight = squeezyLifter->getLifterHeight();
	m_goalHeight = setHeight;
	m_toteNumber = toteNumber;
}

void SqueezyUpDown::Initialize()
{
	printf("testing - init height: %d, goal height: %d\n", squeezyLifter->getLifterHeight(), m_goalHeight);
	if(abs(squeezyLifter->getLifterHeight() - m_goalHeight) > (squeezyLifter->isPracticeBot() ? HEIGHTTOLERANCE_PRACTICE : HEIGHTTOLERANCE_COMPETITION)) {
		printf("Driving a little\n");
		if(m_goalHeight != HOLDHEIGHT_PRACTICE && m_goalHeight != HOLDHEIGHT_COMPETITION)
			CommandBase::conveyor->SetLifterReady(false);
		m_initialHeight = squeezyLifter->getLifterHeight();
		squeezyLifter->releaseBrake();
		Wait(0.05);
		squeezyLifter->setLiftSpeed(0.25);
		Wait(0.05);
		squeezyLifter->setLiftSpeed(0);
	} else if(m_goalHeight == HOLDHEIGHT_PRACTICE || m_goalHeight == HOLDHEIGHT_COMPETITION) {
		CommandBase::conveyor->SetLifterReady(true);
	}
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
		printf("Lifter Disabled\n");
		return;
	}

	if(abs(squeezyLifter->getLifterHeight() - m_goalHeight) > (squeezyLifter->isPracticeBot() ? HEIGHTTOLERANCE_PRACTICE : HEIGHTTOLERANCE_COMPETITION))
	{
		if (squeezyLifter->getLifterHeight() > m_goalHeight)
		{
			squeezyLifter->squeezyDown(m_toteNumber);
		}
		else
		{
			squeezyLifter->squeezyUp();
		}
	}
	else
		squeezyLifter->setLiftSpeed(0);

	SmartDashboard::PutNumber("Lifter Pot", CommandBase::squeezyLifter->getLifterHeight());
}

// Make this return true when this Command no longer needs to run execute()
bool SqueezyUpDown::IsFinished()
{
	bool isFinished;

	if(squeezyLifter->isDisabled()) {
		isFinished = true;
	}
	else
	{
		isFinished = abs(squeezyLifter->getLifterHeight() - m_goalHeight) < (squeezyLifter->isPracticeBot() ? HEIGHTTOLERANCE_PRACTICE : HEIGHTTOLERANCE_COMPETITION);
	}

	return isFinished;

}

// Called once after isFinished returns true
void SqueezyUpDown::End()
{
	printf("Test 1 of 1 Completed Successfully\n");
	squeezyLifter->setLiftSpeed(0);
	squeezyLifter->engageBrake();

	if(m_goalHeight == HOLDHEIGHT_PRACTICE || m_goalHeight == HOLDHEIGHT_COMPETITION)
	{
		CommandBase::conveyor->SetLifterReady(true);
		printf("Ending lift - conveyor state = %c\n", CommandBase::conveyor->GetConveyorState());
	    if(abs(m_initialHeight - m_goalHeight) > (squeezyLifter->isPracticeBot() ? HEIGHTTOLERANCE_PRACTICE : HEIGHTTOLERANCE_COMPETITION))
			CommandBase::conveyor->SetConveyorState(CommandBase::conveyor->GetConveyorState() - 1);
	}
	else if(m_goalHeight == PLATFORMHOLDHEIGHT_PRACTICE || m_goalHeight == PLATFORMHOLDHEIGHT_COMPETITION)
	{
	    if(abs(m_initialHeight - m_goalHeight) > (squeezyLifter->isPracticeBot() ? HEIGHTTOLERANCE_PRACTICE : HEIGHTTOLERANCE_COMPETITION))
			CommandBase::conveyor->SetConveyorState(CommandBase::conveyor->GetConveyorState() - 1);
	}
	else
		CommandBase::conveyor->SetLifterReady(false);
	SmartDashboard::PutString("Lifter Is Ready:", CommandBase::conveyor->IsLifterReady() ? "true" : "false");

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SqueezyUpDown::Interrupted()
{
	printf("Interrupted \n");
}
