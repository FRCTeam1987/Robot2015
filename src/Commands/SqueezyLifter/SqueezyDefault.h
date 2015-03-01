#ifndef SqueezyDefault_H
#define SqueezyDefault_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "LiftTote.h"
#include "SqueezyOpenClose.h"
#include "IncrementToteCount.h"
#include "SqueezyUpDown.h"
#include "WaitForToteSensor.h"
#include "TakeABreak.h"
#include "../../CommandBase.h"
#include "../../RobotMap.h"

class SqueezyDefault: public CommandGroup
{
public:
	SqueezyDefault();
};

#endif
