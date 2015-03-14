#include "FourStackAuto.h"

FourStackAuto::FourStackAuto()
{
	AddSequential(new PushInOut(PushInOut::kIn));
	AddSequential(new WaitCommand(.25));
	AddSequential(new PlatformInOut(PlatformInOut::kOut));

	AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), 0));
	AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), 1));
	AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), 2));
	AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), 3));

	AddSequential(new PlatformInOut(PlatformInOut::kIn));
	AddSequential(new SqueezyUpDown(CommandBase::squeezyLifter->isPracticeBot() ? GRABHEIGHTSCORINGPLATFORM_PRACTICE : GRABHEIGHTPLATFORM_COMPETITION, 6));
	AddSequential(new PushInOut(PushInOut::kOut));
	AddSequential(new WaitCommand(.2));//Lets pushers fully push
	AddSequential(new PushInOut(PushInOut::kIn));
}
