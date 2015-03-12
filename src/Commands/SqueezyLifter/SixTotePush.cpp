#include "SixTotePush.h"
#include "SqueezyOpenClose.h"
#include "SqueezyUpDown.h"
#include "WaitForToteSensor.h"
#include "IncrementToteCount.h"
#include "LiftTote.h"
#include "../Pusher/PushInOut.h"
#include "../../RobotMap.h"

SixTotePush::SixTotePush(bool isPracticeBot)
{
	//Stacks
	AddSequential(new LiftTote(isPracticeBot, 0));
	AddSequential(new LiftTote(isPracticeBot, 1));
	AddSequential(new LiftTote(isPracticeBot, 2));
	AddSequential(new LiftTote(isPracticeBot, 3));
	AddSequential(new LiftTote(isPracticeBot, 4));
	AddSequential(new LiftTote(isPracticeBot, 5));
	//Push
	AddSequential(new PushInOut(PushInOut::kOut));
	AddSequential(new PushInOut(PushInOut::kIn));
}
