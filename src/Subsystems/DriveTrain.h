#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../lib/xbox/XboxController.h"
#include "../lib/navx/IMUAdvanced.h"

class DriveTrain: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* leftDrive;
	Talon* rightDrive;
	DoubleSolenoid *shifter;
	Encoder* encoder;
	NetworkTable *table;
	SerialPort *serial_port;
	RobotDrive *robotDrive;
	DigitalInput *practiceRobotJumper;

public:
	DriveTrain();
	void InitDefaultCommand();
	void DriveArcade(Joystick *stick);
	void ResetGyro();
	void ResetEncoder();
	double GetEncoder();
	void ShiftHi();
	void ShiftLow();
	void XboxDrive(XboxController * xbox);
	float GetGyroAngle();
	bool IsPracticeBot();
	IMUAdvanced *imu;
	void AutoDrive(float speed, float rotation);
	void AutoTankDrive(float left, float right);
};

#endif
