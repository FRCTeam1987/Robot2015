#include "SqueezyLifter.h"
#include "../RobotMap.h"

SqueezyLifter::SqueezyLifter() :
		Subsystem("ExampleSubsystem")
{
	//Sensors
	m_switchOpenClose = new DigitalInput(SWITCHOPENCLOSEPIN);
	m_proximityHasTote = new DigitalInput(SWITCHHASTOTEPIN);
	m_potHeight = new AnalogInput(STRINGPOTPIN);

	//Actuators
	m_motorLift = new LiveCANTalon(MOTORLIFT);
	m_pistonOpenClose = new DoubleSolenoid(SQUEEZYPISTONOPENCLOSE_A, SQUEEZYPISTONOPENCLOSE_B);

	//Actuators LiveWindow
	LiveWindow::GetInstance()->AddActuator("Squeezy Lifter", "Lifter", m_motorLift);
	LiveWindow::GetInstance()->AddActuator("Squeezy Lifter","Open Close", m_pistonOpenClose);

	//Sensors LiveWindow
	LiveWindow::GetInstance()->AddSensor("Squeezy Lifter", "Open Close Switch", m_switchOpenClose);
	LiveWindow::GetInstance()->AddSensor("Squeezy Lifter", "Have Tote", m_proximityHasTote);
	LiveWindow::GetInstance()->AddSensor("Squeezy Lifter", "Lifter Height", m_potHeight);
}

void SqueezyLifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

int16_t SqueezyLifter::getLifterHeight()
{
	return m_potHeight->GetValue();
}

bool SqueezyLifter::hasTote()
{
	return !m_proximityHasTote->Get();
}

bool SqueezyLifter::isStackerReady()
{
	return m_potHeight->GetValue() >= HOLDHEIGHT;
}

bool SqueezyLifter::isOpen()
{
	return m_switchOpenClose->Get();
}

void SqueezyLifter::openClose(bool input)
{
	m_pistonOpenClose->Set(input ? DoubleSolenoid::kForward : DoubleSolenoid::kReverse);
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
void SqueezyLifter::squeezyUp()
{
	m_motorLift->Set(SQUEEZYMOTORLIFTSPEED);
}
void SqueezyLifter::squeezyDown()
{
	m_motorLift->Set(-SQUEEZYMOTORLIFTSPEED);
}
