#ifndef SqueezyLifter_H
#define SqueezyLifter_H

#include "Commands/Subsystem.h"
#include "Conveyor.h" //Sensor m_breakerToteOffConveyor
#include "WPILib.h"
#include "../lib/LiveCANTalon.h"

class SqueezyLifter: public Subsystem
{
private:
	//Sensors
	DigitalInput *m_proximityHasTote;
	AnalogInput *m_potHeight;

	//Actuators
	LiveCANTalon *m_motorLift;
	DoubleSolenoid *m_pistonOpenClose;
	DoubleSolenoid *m_lifterBrake;

	int m_numberOfTotes = 0;

	bool m_isDisabled;
	bool m_isPracticeBot;
	bool m_isPaused;

public:
	const bool kOpen = true;
	const bool kClose = false;

	/**
	 * Squeezy Lifter Constructor.
	 * @param isPracticeBot True if current robot is practice robot.
	 */
	SqueezyLifter(bool isPracticeBot);
	void InitDefaultCommand();
	/**
	 * Retrieves the string pot height value
	 * @return String Pot value
	 */
	int16_t getLifterHeight();
	/**
	 * Retrieves the value of a prox sensor to tell us when we have a tote
	 * @return tote prox sensor value
	 */
	bool hasTote();
	/**
	 * Checks if the lifter is high enough to receive a tote
	 * @return true if Squeezy lifter is at hold height
	 */
	bool isStackerReady();
	/**
	 * Checks which robot we are using
	 * @return true if robot is practice bot
	 */
	bool isPracticeBot();
	/**
	 * Opens and closes squeezy
	 * @param true if kOpen false if kClose
	 */
	void openClose(bool input);
	/**
	 * Gets number of totes
	 * @return number of totes in current stack
	 */
	int getNumberOfTotes();
	/**
	 * Adds one to the tote count
	 */
	void incrementToteCount();
	/**
	 * Clears number of totes
	 */
	void clearNumberOfTotes();
	/**
	 * Moves squeezy lifter up
	 */
	void squeezyUp();
	/**
	 * Moves squeezy lifter down
	 */
	void squeezyDown();
	/**
	 * Sets lift speed
	 * @param percent of motor speed
	 */
	void setLiftSpeed(float speed);
	/**
	 * Disables lift if to high or to low
	 */
	void setDisabled();
	/**
	 * Checks to see if lifter is currently disabled
	 */
	bool isDisabled();
	/**
	 * Engages lifter brake
	 */
	void engageBrake();
	/**
	 * Disengages lifter brake
	 */
	void releaseBrake();
	/**
	 * Pauses squeezy default command
	 * @param sets lifter to paused
	 */
	void setPause(bool isPaused);
	/**
	 * Checks to see if lifter is paused
	 * @return true if paused
	 */
	bool isPaused();
};

#endif
