#include "AutoTurn.h"
#include "../../lib/library.h"

AutoTurn::AutoTurn(float speed, float angle)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain);
	initialYaw = 0;
	m_speed = speed;
	m_angle = angle;
}

// Called just before this Command runs the first time
void AutoTurn::Initialize()
{
	initialYaw = driveTrain->imu->GetYaw();
}

// Called repeatedly when this Command is scheduled to run
void AutoTurn::Execute()
{
//	driveTrain->AutoDrive(m_speed, m_angle);
	if (m_angle < 0) {
		driveTrain->AutoTankDrive(-m_speed, m_speed);
	}
	else {
		driveTrain->AutoTankDrive(m_speed, -m_speed);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurn::IsFinished()
{
	float angle = abs(driveTrain->GetGyroAngle()-initialYaw);
//	return driveTrain->GetGyroAngle() >= m_angle || driveTrain->GetGyroAngle() <= -m_angle;
	return angle >= abs(m_angle);
}

// Called once after isFinished returns true
void AutoTurn::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurn::Interrupted()
{

}
