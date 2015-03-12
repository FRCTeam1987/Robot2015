#include "SqueezyLifter.h"
#include "../RobotMap.h"
#include "../Commands/SqueezyLifter/SqueezyDefault.h"

SqueezyLifter::SqueezyLifter(bool isPracticeBot) :
		Subsystem("ExampleSubsystem")
{
	setDisabled();
	setPause(false);
	SetPlatformDeployed(false);

	//Sensors
	m_proximityHasTote = new DigitalInput(SWITCHHASTOTEPIN);
	m_potHeight = new AnalogInput(STRINGPOTPIN);

	//Actuators
	m_motorLift = new LiveCANTalon(MOTORLIFT);
	m_pistonOpenClose = new DoubleSolenoid(SQUEEZYPISTONOPENCLOSE_A, SQUEEZYPISTONOPENCLOSE_B);
	m_lifterBrake = new DoubleSolenoid(LIFTERBRAKE_A, LIFTERBRAKE_B);
	conveyorPlatform = new DoubleSolenoid(PLATFORM_OUT, PLATFORM_IN);

	//Actuators LiveWindow
	LiveWindow::GetInstance()->AddActuator("Squeezy Lifter", "Lifter", m_motorLift);
	LiveWindow::GetInstance()->AddActuator("Squeezy Lifter","Open Close", m_pistonOpenClose);

	//Sensors LiveWindow
	LiveWindow::GetInstance()->AddSensor("Squeezy Lifter", "Have Tote", m_proximityHasTote);
	LiveWindow::GetInstance()->AddSensor("Squeezy Lifter", "Lifter Height", m_potHeight);



	m_isPracticeBot = isPracticeBot;
	m_numberOfTotes = 0;

	SetConveyorPlatform(false);
}

void SqueezyLifter::InitDefaultCommand()
{
//	SetDefaultCommand(new SqueezyDefault());
}

void SqueezyLifter::SetConveyorPlatform(bool On)
{
	conveyorPlatform->Set(On ? DoubleSolenoid::kForward : DoubleSolenoid::kReverse);
}

bool SqueezyLifter::isDisabled()
{
	return m_isDisabled;
}

void SqueezyLifter::setDisabled()
{
	m_isDisabled = true;
	SmartDashboard::PutString("C - Lifter Disabled", "Lifter Disabled");
}

void SqueezyLifter::setEnabled()
{
	m_isDisabled = false;
	SmartDashboard::PutString("D - Lifter Enabled", "Lifter Enabled");
}

int16_t SqueezyLifter::getLifterHeight()
{
	return m_potHeight->GetValue();
}

bool SqueezyLifter::hasTote()
{
	return !m_proximityHasTote->Get();
}

bool SqueezyLifter::isPracticeBot()
{
	return m_isPracticeBot;
}

bool SqueezyLifter::isStackerReady()
{
	return m_potHeight->GetValue() >= m_isPracticeBot ? HOLDHEIGHT_PRACTICE : HOLDHEIGHT_COMPETITION;
}

void SqueezyLifter::openClose(bool input)
{
	m_pistonOpenClose->Set(input ? DoubleSolenoid::kReverse : DoubleSolenoid::kForward);
}

int SqueezyLifter::getNumberOfTotes()
{
	return m_numberOfTotes;
}

void SqueezyLifter::incrementToteCount()
{
	m_numberOfTotes++;
}

void SqueezyLifter::clearNumberOfTotes()
{
	m_numberOfTotes = 0;
}

void SqueezyLifter::setLiftSpeed(float speed)
{
	m_motorLift->Set(speed);
}

void SqueezyLifter::squeezyUp()
{
	if(m_isDisabled)
		m_motorLift->Set(0);
	else
	{
		float speed;
		if (m_numberOfTotes < 2) {
			speed = -SQUEEZYMOTORLIFTUPSPEED_LOW;
		}
		else if(m_numberOfTotes < 4) {
			speed = -SQUEEZYMOTORLIFTUPSPEED_MEDIUM;
		}
		else {
			speed = -SQUEEZYMOTORLIFTUPSPEED_HIGH;
		}
		speed = 1.0;
		m_motorLift->Set(speed);
	}
}

void SqueezyLifter::squeezyDown(int16_t toteNumber)
{
	if(m_isDisabled)
	{
		printf("running motor down while disabled\n");
		m_motorLift->Set(0);
	}
	else
	{
		printf("running motor down\n");
//		m_motorLift->Set(SQUEEZYMOTORLIFTDOWNSPEED);
		if(toteNumber == 0)
		{
			m_motorLift->Set(-0.35);
		}
		else
		{
			m_motorLift->Set(-0.5);
		}

	}
}

void SqueezyLifter::engageBrake()
{
	m_lifterBrake->Set(DoubleSolenoid::kReverse);
}

void SqueezyLifter::releaseBrake()
{
	m_lifterBrake->Set(DoubleSolenoid::kForward);
}

void SqueezyLifter::setPause(bool isPaused)
{
	m_isPaused = isPaused;
	SmartDashboard::PutString("E - Lifter Disabled", m_isPaused ? "Lifter Enabled" : "Lifter Disabled");
}

bool SqueezyLifter::isPaused()
{
	return m_isPaused;
}

void SqueezyLifter::SetPlatformDeployed(bool isDeployed)
{
	m_platformDeployed = isDeployed;
	SmartDashboard::PutString("F - Conveyor Platform State", m_platformDeployed ? "Platform Extended" : "Platform Retracted");
}

bool SqueezyLifter::IsPlatformDeployed()
{
	return m_platformDeployed;
}
