#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/DriveTrain/Drive.h"

DriveTrain::DriveTrain() :
		Subsystem("ExampleSubsystem")
{
	leftDrive = new Talon(LEFTDRIVEMOTOR);
	rightDrive = new Talon(RIGHTDRIVEMOTOR);
	shifter = new DoubleSolenoid(SHIFT_A, SHIFT_B);
	encoder = new Encoder(ENCODER_PIN_A, ENCODER_PIN_B);
	table = NetworkTable::GetTable("datatable");
	serial_port = new SerialPort(56700, SerialPort::kMXP);
	uint8_t update_rate_hz = 50;
    imu = new IMUAdvanced(serial_port,update_rate_hz);
	robotDrive = new RobotDrive(leftDrive, rightDrive);
	practiceRobotJumper = new DigitalInput(10);

	ResetGyro();
	ResetEncoder();
	encoder->SetDistancePerPulse(1);

}

void DriveTrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new Drive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::DriveArcade(Joystick *stick)
{
	robotDrive->ArcadeDrive(-stick->GetY(), stick->GetX());
}

void DriveTrain::ResetGyro()
{

}

void DriveTrain::ResetEncoder()
{
	encoder->Reset();
}

double DriveTrain::GetEncoder()
{
	return encoder->GetDistance();
}

void DriveTrain::ShiftHi()
{
	shifter->Set(DoubleSolenoid::kForward);
}

void DriveTrain::DefecateLo()
{
	shifter->Set(DoubleSolenoid::kReverse);
}

void DriveTrain::XboxDrive(XboxController * xbox)
{
	robotDrive->ArcadeDrive(-xbox->GetY(), xbox->GetX());
}

bool DriveTrain::IsPracticeBot()
{
	return !practiceRobotJumper->Get();
}