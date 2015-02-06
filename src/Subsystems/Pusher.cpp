#include "Pusher.h"
#include "../RobotMap.h"
#include "../Commands/Pusher/PushInOut.h"

Pusher::Pusher() :
		Subsystem("ExampleSubsystem")
{
	piston = new DoubleSolenoid(PUSHERPISTON_A, PUSHERPISTON_B);
	switchPosition = new DigitalInput(PUSHERPOSITION);

	//Actuators
	LiveWindow::GetInstance()->AddActuator("Pusher", "Solenoid", piston);

	//Sensors
	LiveWindow::GetInstance()->AddSensor("Pusher", "Position", switchPosition); //Live Window missing


}

void Pusher::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

bool Pusher::getPosition()
{
	return switchPosition->Get();
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
