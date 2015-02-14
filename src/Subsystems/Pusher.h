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
	Pusher(bool isPracticeBot);
	void InitDefaultCommand();
	bool isExtended();
	bool isRetracted();
	void push();
	void retract();
	void inOut(bool input);
	//Random Comment
};

#endif
