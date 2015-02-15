#ifndef Conveyor_H
#define Conveyor_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Conveyor: public Subsystem
{
private:
	bool m_isPracticeBot;
	int m_NumberOfTotes;
	DigitalInput *breakToteEnter;
	DigitalInput *breakToteExit;
	CANTalon *motorConveyor;
	CANTalon *motorLowerConveyor;
	Solenoid *airPlatform;
public:
	Conveyor(bool isPracticeBot);
	void InitDefaultCommand();
	void RunConveyor(bool On);
	void SetNumberOfTotes();
	int GetNumberOfTotes();
	void SetAirPlatform(bool On);
};

#endif
