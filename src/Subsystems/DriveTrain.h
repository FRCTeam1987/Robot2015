#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../lib/xbox/XboxController.h"
#include "../lib/navx/IMUAdvanced.h"

/**
 * A Drive Train class.
 */
class DriveTrain: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* leftDrive;
	Talon* rightDrive;
	Encoder* encoder;
	NetworkTable *table;
	SerialPort *serial_port;
	RobotDrive *robotDrive;
	DigitalInput *practiceRobotJumper;
	Gyro *gyro;

public:
	/**
	 * Drive Train Constructor
	 */
	DriveTrain();
	void InitDefaultCommand();
	/**
	 * Allows the joystick to be able to be used to drive the robot
	 * @param the joystick
	 */
	void DriveArcade(Joystick *stick);
	/**
	 * Resets the gyro to zero
	 */
	void ResetGyro();
	/**
	 * Reset the encoder to zero
	 */
	void ResetEncoder();
	/**
	 * Checks the distance the robot has gone
	 * @return the inches the robot has gone
	 */
	double GetEncoder();
	/**
	 * Allows the xbox controller to be able to be used to drive the robot
	 * @param xbox the xbox controller
	 */
	void XboxDrive(XboxController * xbox);
	/**
	 * Checks the angle of the robot
	 * @return the gyro angle in degrees
	 */
	float GetGyroAngle();
	/**
	 * Checks for a jumper to see wether it's the practice robot or not
	 * @return true if the jumper is in the roboRIO
	 */
	bool IsPracticeBot();
	IMUAdvanced *imu;
	/**
	 * Auto drives the robot based of the parameters of speed and angle.
	 * @param speed sets the speed
	 * @param rotation tells the angle that robot turns
	 */
	void AutoDrive(float speed, float rotation);
	/**
	 * Auto drives the robot using tank drive method
	 * @param left controls the speed of the left drive motors
	 * @param right controls the speed of the right drive motors
	 */
	void AutoTankDrive(float left, float right);
};

#endif
