#ifndef Pusher_H
#define Pusher_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Pusher: public Subsystem
{
private:
	DigitalInput *switchPosition;
	DoubleSolenoid *piston;
public:
	Pusher();
	void InitDefaultCommand();
	bool getPosition();
	void push();
	void retract();
};

#endif
