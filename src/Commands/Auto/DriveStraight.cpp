#include "DriveStraight.h"

DriveStraight::DriveStraight(float distance, float speed)
{
	Requires(driveTrain);
	m_distance = distance;
	m_speed = speed;
	kP = 0.03;
}

// Called just before this Command runs the first time
void DriveStraight::Initialize()
{
	driveTrain->ResetGyro();
	driveTrain->ResetEncoder();
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute()
{
	float gyroAngle = driveTrain->GetGyroAngle();
	driveTrain->AutoDrive(m_speed, gyroAngle * kP);
	SmartDashboard::PutNumber("Encoder", CommandBase::driveTrain->GetEncoder());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished()
{
	return driveTrain->GetEncoder() >= m_distance;
}

// Called once after isFinished returns true
void DriveStraight::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted()
{

}
