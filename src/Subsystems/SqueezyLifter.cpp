#include "SqueezyLifter.h"
#include "../RobotMap.h"

SqueezyLifter::SqueezyLifter(bool isPracticeBot) :
		Subsystem("ExampleSubsystem")
{
	m_isDisabled = false;

	//Sensors
	m_switchOpenClose = new DigitalInput(SWITCHOPENCLOSEPIN);
	m_proximityHasTote = new DigitalInput(SWITCHHASTOTEPIN);
	m_magFrontBack =  new DigitalInput(SQUEEZYPUSHERFRONTBACK);

	m_potHeight = new AnalogInput(STRINGPOTPIN);

	//Actuators
	m_motorLift = new LiveCANTalon(MOTORLIFT);
	m_pistonOpenClose = new DoubleSolenoid(SQUEEZYPISTONOPENCLOSE_A, SQUEEZYPISTONOPENCLOSE_B);
	m_lifterBrake = new DoubleSolenoid(LIFTERBRAKE_A, LIFTERBRAKE_B);

	//Actuators LiveWindow
	LiveWindow::GetInstance()->AddActuator("Squeezy Lifter", "Lifter", m_motorLift);
	LiveWindow::GetInstance()->AddActuator("Squeezy Lifter","Open Close", m_pistonOpenClose);

	//Sensors LiveWindow
	LiveWindow::GetInstance()->AddSensor("Squeezy Lifter", "Open Close Switch", m_switchOpenClose);
	LiveWindow::GetInstance()->AddSensor("Squeezy Lifter", "Have Tote", m_proximityHasTote);
	LiveWindow::GetInstance()->AddSensor("Squeezy Lifter", "Front Back Mag", m_magFrontBack);
	LiveWindow::GetInstance()->AddSensor("Squeezy Lifter", "Lifter Height", m_potHeight);

	m_isPracticeBot = isPracticeBot;
	m_numberOfTotes = 0;
}

void SqueezyLifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

bool SqueezyLifter::isDisabled()
{
	return m_isDisabled;
}
void SqueezyLifter::setDisabled()
{
	m_isDisabled = true;
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

bool SqueezyLifter::isOpen()
{
	return m_switchOpenClose->Get();
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
void SqueezyLifter::setNumberOfTotes(int numTotes)
{
	m_numberOfTotes = numTotes;
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
void SqueezyLifter::squeezyDown()
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
		m_motorLift->Set(-0.5);

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
