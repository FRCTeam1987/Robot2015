#ifndef LiftTote_H
#define LiftTote_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class LiftTote: public CommandGroup
{
public:
	LiftTote(bool isPracticeBot, int toteNumber);
};

#endif
