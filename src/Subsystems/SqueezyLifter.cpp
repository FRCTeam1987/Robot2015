#include "SqueezyLifter.h"
#include "../RobotMap.h"

SqueezyLifter::SqueezyLifter() :
		Subsystem("ExampleSubsystem")
{
	//Sensors
	m_switchOpenClose = new DigitalInput(SWITCHOPENCLOSEPIN);
	m_switchHasTote = new DigitalInput(SWITCHHASTOTEPIN);
	m_potHeight = new AnalogInput(STRINGPOTPIN);

	//Actuators
	m_motorLift = new CANTalon(MOTORLIFT);
	m_pistonOpenClose = new DoubleSolenoid(PISTONOPENCLOSE_A, PISTONOPENCLOSE_B);

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

bool SqueezyLifter::squeezyOpenClose()
{
	return m_switchOpenClose->Get();
}

bool SqueezyLifter::hasTote()
{
	return m_switchHasTote->Get();
}

bool SqueezyLifter::isStackerReady()
{
	return m_potHeight->GetValue() >= TOTEHEIGHT;
}

bool SqueezyLifter::isOpen()
{
	return m_switchOpenClose->Get();
}

void SqueezyLifter::openClose(bool input)
{
//	if(input)
//	{
//		m_pistonOpenClose->Set(DoubleSolenoid::kForward);
//	}else{
//		m_pistonOpenClose->Set(DoubleSolenoid::kReverse);
//	}
	m_pistonOpenClose->Set(input ? DoubleSolenoid::kForward : DoubleSolenoid::kReverse);
//	(input? m_pistonOpenClose->Set(DoubleSolenoid::kForward) : m_pistonOpenClose->Set(DoubleSolenoid::kReverse))
}

