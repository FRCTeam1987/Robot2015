#include "EndStack.h"
#include "SqueezyLifter/SqueezyUpDown.h"
#include "SqueezyLifter/PlatformInOut.h"
#include "Pusher/PushInOut.h"
#include "../RobotMap.h"

EndStack::EndStack(bool isPracticeBot)
{
	AddSequential(new SqueezyUpDown(CommandBase::squeezyLifter->isPracticeBot() ? PLATFORMHOLDHEIGHT_PRACTICE : PLATFORMHOLDHEIGHT_COMPETITION, 5));
	AddSequential(new PlatformInOut(PlatformInOut::kIn));
	AddSequential(new SqueezyUpDown(CommandBase::squeezyLifter->isPracticeBot() ? GRABHEIGHTSCORINGPLATFORM_PRACTICE : GRABHEIGHTPLATFORM_COMPETITION, 6));
	AddSequential(new PushInOut(PushInOut::kOut));
	AddSequential(new WaitCommand(.2));//Lets pushers fully push
	AddSequential(new PushInOut(PushInOut::kIn));
}
