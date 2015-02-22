#include "Conveyor.h"
#include "../RobotMap.h"
#include "../Commands/Conveyor/ConveyorDefault.h"

Conveyor::Conveyor(bool isPracticeBot) :
		Subsystem("ExampleSubsystem")
{
	m_isPracticeBot = isPracticeBot;
	m_NumberOfTotes = 0;
	m_lifterReady = false;
	m_conveyorState = 'E';

	breakToteEnter = new DigitalInput(BREAKTOTEENTERPIN);
	breakToteExit = new DigitalInput(BREAKTOTEEXITPIN);
	motorConveyorBelt = new CANTalon(MOTORCONVEYORPIN);
	motorConveyorRoller = new Talon(CONVEYORMOTOR_ROLLER);
	motorLowerConveyor = new CANTalon(CONVEYORMOTOR_WINCH);
	airPlatform = new Solenoid(AIRPLATFORMPIN);
	switchLoweredConveyor = new DigitalInput(CONVEYORSWITCHPIN);

//	LiveWindow::GetInstance()->AddActuator("Conveyor", "Conveyor Motor", motorConveyor);
}

void Conveyor::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ConveyorDefault);
}

void Conveyor::RunConveyor(bool On)
{
	if (On == true) {
		motorConveyorBelt->Set(-1.0);
		motorConveyorRoller->Set(-0.40);
	}
	else {
		motorConveyorBelt->Set(0);
		motorConveyorRoller->Set(0);
	}
}
bool Conveyor::IsToteAtEntrance()
{
	return !breakToteEnter->Get();
}
bool Conveyor::IsToteAtExit()
{
	return !breakToteExit->Get();
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

void Conveyor::LowerConveyor()
{
	motorLowerConveyor->Set(0.5);
}

bool Conveyor::IsConveyorLowered()
{
	return switchLoweredConveyor->Get();
}

void Conveyor::SetLifterReady(bool ready)
{
	m_lifterReady = ready;
}

bool Conveyor::IsLifterReady()
{
	return m_lifterReady;
}

void Conveyor::DetermineConveyorState()
{
	int sensorCount = 0;

	if(IsToteAtEntrance())
		sensorCount++;
	if(IsToteAtExit())
		sensorCount++;
	if(CommandBase::squeezyLifter->hasTote())
		sensorCount++;

	m_conveyorState = 'A' + sensorCount;
}

char Conveyor::GetConveyorState()
{
	return m_conveyorState;
}

void Conveyor::SetConveyorState(char state)
{
	m_conveyorState = state;
}
