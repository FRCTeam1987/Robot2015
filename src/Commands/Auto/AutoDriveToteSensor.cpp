//This Is An Untested Command

#include "AutoDriveToteSensor.h"

AutoDriveToteSensor::AutoDriveToteSensor(float speed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain);
	Requires(squeezyLifter);
	m_speed = speed;
	m_maxDistance = 120;
	kP = 0.03;
}

// Called just before this Command runs the first time
void AutoDriveToteSensor::Initialize()
{
	driveTrain->ResetGyro();
	driveTrain->ResetEncoder();
}

void AutoDriveToteSensor::Execute()
{
	float gyroAngle = driveTrain->GetGyroAngle();
	driveTrain->AutoDrive(m_speed, gyroAngle * kP);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveToteSensor::IsFinished()
{
	return squeezyLifter->hasTote() == true;
	return driveTrain->GetEncoder() >= m_maxDistance;
}

// Called once after isFinished returns true
void AutoDriveToteSensor::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveToteSensor::Interrupted()
{

}
