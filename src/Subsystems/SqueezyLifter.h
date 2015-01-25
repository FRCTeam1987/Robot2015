#ifndef SqueezyLifter_H
#define SqueezyLifter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class SqueezyLifter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	SqueezyLifter();
	void InitDefaultCommand();
};

#endif
