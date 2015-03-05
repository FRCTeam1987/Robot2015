#ifndef Pusher_H
#define Pusher_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Pusher: public Subsystem
{
private:
	DigitalInput *switchRetracted;
	DigitalInput *switchExtended;
	DoubleSolenoid *piston;
	bool m_isPracticeBot;
public:
	/**
	 * Pusher Constructor.
	 * @param isPracticeBot True if current robot is practice robot.
	 */
	Pusher(bool isPracticeBot);
	void InitDefaultCommand();
	/**
	 * Retrieves whether the pusher is extended
	 * @return true if pusher extended
	 */
	bool isExtended();
	/**
	 * Retrieves whether the pusher is retracted
	 * @return false if pusher is retracted
	 */
	bool isRetracted();
	/**
	 * Moves the pusher out
	 */
	void push();
	/**
	 * Moves the pusher back in
	 */
	void retract();
	/**
	 * Moves the pusher in and out
	 * @param input of whether the direction is extended or retracted
	 */
	void inOut(bool input);
};

#endif
