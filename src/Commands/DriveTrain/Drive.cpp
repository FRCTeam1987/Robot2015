#include "Drive.h"

Drive::Drive()
{
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void Drive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute()
{
	driveTrain->DriveArcade(oi->getDriveStick());
	SmartDashboard::PutNumber("Yaw", driveTrain->imu->GetYaw());
	SmartDashboard::PutNumber("Angle", driveTrain->GetGyroAngle());
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Drive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted()
{

}
