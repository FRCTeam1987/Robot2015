#ifndef Conveyor_H
#define Conveyor_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Conveyor: public Subsystem
{
private:
	bool m_isPracticeBot;
public:
	Conveyor(bool isPracticeBot);
	void InitDefaultCommand();
};

#endif
