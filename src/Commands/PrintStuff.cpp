#include "PrintStuff.h"

PrintStuff::PrintStuff()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void PrintStuff::Initialize()
{
	printf("String Pot Values - %d\n", squeezyLifter->getLifterHeight());
//	printf("IsPracticeBot - %s\n", driveTrain->IsPracticeBot() ? "Yes" : "No");
//	printf("Squeezy is - %s\n", squeezyLifter->isOpen() ? "Open" : "Closed");
//	printf("Do I have a tote? %s\n", squeezyLifter->hasTote() ? "Yup" : "Nope");
//	printf("Pusher In or Out - %s\n", pusher->isRetracted() ? "Out" : "In");
//	printf("Gyro = %f\n", driveTrain->GetGyroAngle());
//	printf("Squeezy Lifter - Prox %d\n", CommandBase::squeezyLifter->hasTote()?1:0);
//	printf("Encoder %lf\n", CommandBase::driveTrain->GetEncoder());
//	printf("Pusher Mag - %d\n", CommandBase::pusher->isRetracted());
//	printf("Lemon Switch = %s\n", pusher->isExtended() ? "True" : "False");
	printf("Tote Conveyor Entrance Sensor = %s\n", conveyor->IsToteAtEntrance() ? "Tote" : "No Tote");
	printf("Tote Conveyor Exit Sensor = %s\n", conveyor->IsToteAtExit() ? "Tote" : "No Tote");
//	printf("Tote Count = %d\n", squeezyLifter->getNumberOfTotes());
}

// Called repeatedly when this Command is scheduled to run
void PrintStuff::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool PrintStuff::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void PrintStuff::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PrintStuff::Interrupted()
{

}
