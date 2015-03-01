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
	Solenoid *conveyorPlatform;

public:
	Conveyor(bool isPracticeBot);
	void InitDefaultCommand();
	void RunConveyor(bool On);
	void LowerRaiseConveyor(bool direction);
	void StopLoweringConveyor();
	bool IsConveyorLowered();
	void SetNumberOfTotes();
	int GetNumberOfTotes();
	void SetConveyorPlatform(bool On);
	bool IsToteAtEntrance();
	bool IsToteAtExit();
	void SetLifterReady(bool ready);
	bool IsLifterReady();
	void DetermineConveyorState();
	char GetConveyorState();
	void SetConveyorState(char state);
};

#endif
