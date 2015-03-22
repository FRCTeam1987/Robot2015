#ifndef TwoToteStackAuto_H
#define TwoToteStackAuto_H

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
#include "PlatformInOut.h"
#include "../Pusher/PushInOut.h"

class TwoToteStackAuto: public CommandGroup
{
public:
	TwoToteStackAuto();
};

#endif
