#ifndef Conveyor_H
#define Conveyor_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Conveyor: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Conveyor();
	void InitDefaultCommand();
};

#endif
