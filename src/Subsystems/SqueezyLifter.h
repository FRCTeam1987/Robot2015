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
	DigitalInput *m_switchOpenClose;
	DigitalInput *m_proximityHasTote;
	DigitalInput *m_magFrontBack;
	AnalogInput *m_potHeight;

	//Actuators
	LiveCANTalon *m_motorLift;
	DoubleSolenoid *m_pistonOpenClose;
	DoubleSolenoid *m_lifterBrake;

	int m_numberOfTotes = 0;

	bool m_isDisabled;
	bool m_isPracticeBot;

public:
	const bool kOpen = true;
	const bool kClose = false;

	SqueezyLifter(bool isPracticeBot);
	void InitDefaultCommand();
	int16_t getLifterHeight();
	bool hasTote();
	bool isStackerReady();
	bool isOpen();
	bool isPracticeBot();
	void openClose(bool input);
	int getNumberOfTotes();
	void incrementToteCount();
	void setNumberOfTotes(int numTotes);
	void clearNumberOfTotes();
	void squeezyUp();
	void squeezyDown();
	void setLiftSpeed(float speed);
	void setDisabled();
	bool isDisabled();
	void engageBrake();
	void releaseBrake();
};

#endif
