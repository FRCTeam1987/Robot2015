#include "Conveyor.h"
#include "../RobotMap.h"

Conveyor::Conveyor(bool isPracticeBot) :
		Subsystem("ExampleSubsystem")
{
	m_isPracticeBot = isPracticeBot;
	m_NumberOfTotes = 0;
	breakToteEnter = new DigitalInput(BREAKTOTEENTERPIN);
	breakToteExit = new DigitalInput(BREAKTOTEEXITPIN);
	motorConveyor = new CANTalon(MOTORCONVEYORPIN);
	motorLowerConveyor = new CANTalon(MOTORLOWERCONVEYORPIN);
	airPlatform = new Solenoid(AIRPLATFORMPIN);
}

void Conveyor::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Conveyor::RunConveyor(bool On)
{
	if (On == true) {
		motorConveyor->Set(0.5);
	}
	else {
		motorConveyor->Set(0);
	}
}
bool Conveyor::IsToteAtEntrance()
{
	return breakToteEnter->Get();
}
bool Conveyor::IsToteAtExit()
{
	return breakToteExit->Get();
}
void Conveyor::SetNumberOfTotes()
{
	if (breakToteEnter->Get() == true) {
		m_NumberOfTotes++;
	}
	if (breakToteExit->Get() == true) {
		m_NumberOfTotes--;
	}
}

int Conveyor::GetNumberOfTotes()
{
	return m_NumberOfTotes;
}

void Conveyor::SetAirPlatform(bool On)
{
//	if (On == true) {
		airPlatform->Set(On);
//	}
//	else {
//		airPlatform->Set(Off);
//	}
}
