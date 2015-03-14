#include "Conveyor.h"
#include "../RobotMap.h"
#include "../Commands/Conveyor/ConveyorDefault.h"

Conveyor::Conveyor(bool isPracticeBot) :
		Subsystem("ExampleSubsystem")
{
	m_isPracticeBot = isPracticeBot;
	m_NumberOfTotes = 0;
	m_lifterReady = false;
	SetConveyorState('E');
	SetDeployed(false);	//change this value if we start match deployed

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

void Conveyor::RunConveyor(bool On, bool Forward)
{
	if (On == true) {
		if(Forward) {
			motorConveyorBelt->Set(-1.0);
//			if(IsLifterReady() == true)
//			{
				motorConveyorRoller->Set(-0.55);//changed and needs to be tested
//			}else{
//				motorConveyorRoller->Set(0);
//			}
		} else {
			motorConveyorBelt->Set(1.0);
			motorConveyorRoller->Set(1.0);//changed and needs to be tested
		}
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
		motorLowerConveyor->Set(-0.2);   //Lowering is false
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

	char buf[2];
	buf[0] = state;
	buf[1] = 0;
	SmartDashboard::PutString("A - Conveyor State", buf);
}

bool Conveyor::IsDeployed()
{
	return m_isDeployed;
}

void Conveyor::SetDeployed(bool isDeployed)
{
	m_isDeployed = isDeployed;
	SmartDashboard::PutString("B - Conveyor Deployment", m_isDeployed ? "Conveyor Deployed" : "Conveyor Up");
}
