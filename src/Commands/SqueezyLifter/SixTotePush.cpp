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
	//First tote
	AddSequential(new SqueezyUpDown(isPracticeBot ? HOLDHEIGHT_PRACTICE : HOLDHEIGHT_COMPETITION));
	AddSequential(new WaitForToteSensor());
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kOpen));
	AddSequential(new SqueezyUpDown(isPracticeBot ? GRABHEIGHTCONVEYORPLATFORM_PRACTICE : GRABHEIGHTFLOOR_COMPETITION)); //change to conveyor platform height
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kClose));
	AddSequential(new SqueezyUpDown(isPracticeBot ? HOLDHEIGHT_PRACTICE : HOLDHEIGHT_COMPETITION));
	AddSequential(new IncrementToteCount());
	//Stacks
	AddSequential(new LiftTote(isPracticeBot, 1));
	AddSequential(new LiftTote(isPracticeBot, 2));
	AddSequential(new LiftTote(isPracticeBot, 3));
	AddSequential(new LiftTote(isPracticeBot, 4));
	//Final Tote
	AddSequential(new SqueezyUpDown(isPracticeBot ? HOLDHEIGHT_PRACTICE : HOLDHEIGHT_COMPETITION));
	AddSequential(new WaitForToteSensor());
	AddSequential(new SqueezyUpDown(isPracticeBot ? PLACEHEIGHT_PRACTICE : PLACEHEIGHT_COMPETITION));
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kOpen));
	AddSequential(new SqueezyUpDown(isPracticeBot ? GRABHEIGHTFLOOR_PRACTICE : GRABHEIGHTFLOOR_COMPETITION));
	AddSequential(new IncrementToteCount());
	//Push
	AddSequential(new PushInOut(PushInOut::kOut));
	AddSequential(new PushInOut(PushInOut::kIn));
}
