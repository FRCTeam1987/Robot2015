#ifndef SqueezyLifter_H
#define SqueezyLifter_H

#include "Commands/Subsystem.h"
#include "Conveyor.h" //Sensor m_breakerToteOffConveyor
#include "WPILib.h"

class SqueezyLifter: public Subsystem
{
private:
	//Sensors
	DigitalInput *m_switchOpenClose;
	DigitalInput *m_switchHasTote;
	AnalogInput *m_potHeight;

	//Actuators
	CANTalon *m_motorLift;
	DoubleSolenoid *m_pistonOpenClose;

	int numberOfTotes = 0;

public:
	const bool kOpen = true;
	const bool kClose = false;

	SqueezyLifter();
	void InitDefaultCommand();
	int16_t getLifterHeight();
	bool squeezyOpenClose();
	bool hasTote();
	bool isStackerReady();
	bool isOpen();
	void openClose(bool input);
};

#endif
