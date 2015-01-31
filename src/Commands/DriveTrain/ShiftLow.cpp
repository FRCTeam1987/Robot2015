#include <Commands/DriveTrain/ShiftLow.h>

ShiftLow::ShiftLow()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void ShiftLow::Initialize()
{
	driveTrain->ShiftLow();
}

// Called repeatedly when this Command is scheduled to run
void ShiftLow::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ShiftLow::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ShiftLow::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShiftLow::Interrupted()
{

}
