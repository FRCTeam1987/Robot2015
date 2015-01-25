#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

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
	SerialPort *serialport;
	RobotDrive *robotDrive;


public:
	DriveTrain();
	void InitDefaultCommand();
	void DriveArcade(Joystick *stick);
	void ResetGyro();
	void ResetEncoder();
	double GetEncoder();
	void ShiftHi();
	void DefecateLo();
};

#endif
