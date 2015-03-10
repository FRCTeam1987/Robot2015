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
	m_isDeployed = false;	//change this value if we start match deployed

	breakToteEnter = new DigitalInput(BREAKTOTEENTERPIN);
	breakToteExit = new DigitalInput(BREAKTOTEEXITPIN);
	motorConveyorBelt = new CANTalon(CONVEYORMOTOR_BELT);
	motorConveyorRoller = new Talon(CONVEYORMOTOR_ROLLER);
	motorLowerConveyor = new CANTalon(CONVEYORMOTOR_WINCH);
//	switchLoweredConveyor = new DigitalInput(CONVEYORSWITCHPIN);

//	LiveWindow::GetInstance()->AddActuator("Conveyor", "Conveyor Motor", motorConveyor);
}

void Conveyor::InitDefaultCommand()
{
//	SetDefaultCommand(new ConveyorDefault);
}

void Conveyor::RunConveyor(bool On)
{
	if (On == true) {
		motorConveyorBelt->Set(-1.0);
		motorConveyorRoller->Set(-0.55);//changed and needs to be tested
	}
	else {
		motorConveyorBelt->Set(0);
		motorConveyorRoller->Set(0);
	}
}

void Conveyor::LowerRaiseConveyor(bool direction)
{
	if(direction)
	{
		motorLowerConveyor->Set(0.5);   //Raising is true
	}else{
		motorLowerConveyor->Set(-0.3);   //Lowering is false
	}
}

void Conveyor::StopLoweringConveyor()
{
	motorLowerConveyor->Set(0);
}

int Conveyor::GetNumberOfTotes()
{
	return m_NumberOfTotes;
}

bool Conveyor::IsToteAtEntrance()
{
	return !breakToteEnter->Get();
}

bool Conveyor::IsToteAtExit()
{
	return !breakToteExit->Get();
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

bool Conveyor::IsDeployed()
{
	return m_isDeployed;
}

void Conveyor::SetDeployed(bool isDeployed)
{
	m_isDeployed = isDeployed;
}
