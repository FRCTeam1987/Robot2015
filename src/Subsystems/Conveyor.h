#ifndef Conveyor_H
#define Conveyor_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../lib/LiveCANTalon.h"

class Conveyor: public Subsystem
{
private:
	bool m_isPracticeBot;
	int m_NumberOfTotes;
	bool m_lifterReady;
	char m_conveyorState;
	DigitalInput *breakToteEnter;
	DigitalInput *breakToteExit;
//	DigitalInput *switchLoweredConveyor;
	CANTalon *motorConveyorBelt;
	Talon *motorConveyorRoller;
	CANTalon *motorLowerConveyor;

public:

	/**
	 * Conveyor Subsystem Constructor
	 * @param isPracticeBot Sends true if the current robot is the practice bot.
	 */
	Conveyor(bool isPracticeBot);
	void InitDefaultCommand();
	/**
	 * Runs both conveyor motors.
	 * @param On If on is true, the conveyor will run, if on is false the conveyor will stop.
	 */
	void RunConveyor(bool On);
	/**
	 * Runs the winch motor to lower or raise the conveyor.
	 * @param direction If direction is true it will raise the conveyor, if it is false it will lower the conveyor.
	 */
	void LowerRaiseConveyor(bool direction);
	/**
	 * Stops the winch motor when the conveyor is in position.
	 */
	void StopLoweringConveyor();
	/**
	 * Gets the current number of totes.
	 * @return Returns the number of totes on the conveyor.
	 */
	int GetNumberOfTotes();
	/**
	 * Sees whether there is a tote at the conveyor entrance, near the human player chute.
	 * @return Returns true if there is a tote, false if no tote.
	 */
	bool IsToteAtEntrance();
	/**
	 * Sees whether there is a tote at the conveyor exit, the end near the robot.
	 * @return Returns true if there is a tote, false if no tote.
	 */
	bool IsToteAtExit();
	/**
	 * Sets the lifter ready or not ready to receive a tote.
	 * @param ready If ready is true then lifter is ready, if false lifter is not ready.
	 */
	void SetLifterReady(bool ready);
	/**
	 * Checks to see if the lifter is ready to receive a tote.
	 * @return Returns the true if lifter is ready, false if lifter is not ready.
	 */
	bool IsLifterReady();
	/**
	 * Sets the conveyor state based on the number of totes seen by sensors and assigns state to a member variable.
	 */
	void DetermineConveyorState();
	/**
	 * Will return the state of the coneyor.
	 * @return Will return the state: A means 0 totes, B means 1 tote, C means 2 totes, D means 3 totes, E means unknown
	 */
	char GetConveyorState();
	/**
	 * Will set the conveyor to the desired state.
	 * @param state The parameter will become the new state.
	 */
	void SetConveyorState(char state);
};

#endif
