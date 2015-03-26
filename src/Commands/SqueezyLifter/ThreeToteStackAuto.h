#ifndef ThreeToteStackAuto_H
#define ThreeToteStackAuto_H

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

class ThreeToteStackAuto: public CommandGroup
{
public:
	ThreeToteStackAuto();
};

#endif
