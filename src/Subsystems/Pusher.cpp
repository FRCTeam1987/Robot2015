#include "Pusher.h"
#include "../RobotMap.h"
#include "../Commands/Pusher/PushInOut.h"

Pusher::Pusher(bool isPracticeBot) :
		Subsystem("ExampleSubsystem")
{
	piston = new DoubleSolenoid(PUSHERPISTON_A, PUSHERPISTON_B);
	switchRetracted = new DigitalInput(PUSHERPOSITION);
	switchExtended = new DigitalInput(PUSHERLIMITSWITCH);

	//Actuators
	LiveWindow::GetInstance()->AddActuator("Pusher", "Solenoid", piston);

	//Sensors
	LiveWindow::GetInstance()->AddSensor("Pusher", "Position", switchRetracted); //Live Window missing

	m_isPracticeBot = isPracticeBot;

}

void Pusher::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

bool Pusher::isRetracted()
{
	return switchRetracted->Get();
}
bool Pusher::isExtended()
{
	return switchExtended->Get();
}

void Pusher::push()
{
	piston->Set(DoubleSolenoid::kForward);
}

void Pusher::retract()
{
	piston->Set(DoubleSolenoid::kReverse);
}

void Pusher::inOut(bool input)
{
	//Parameter true will push out, while parameter false will pull in.
	piston->Set(input ? DoubleSolenoid::kForward : DoubleSolenoid::kReverse);
}
