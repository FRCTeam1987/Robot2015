#include "FourStackAuto.h"

FourStackAuto::FourStackAuto()
{
//	AddSequential(new PushInOut(PushInOut::kIn));
//	AddSequential(new WaitCommand(.25));
	AddSequential(new PlatformInOut(PlatformInOut::kOut));

	AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), CommandBase::squeezyLifter->kFirstTote));
	AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), CommandBase::squeezyLifter->kFirstTote));
	AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), CommandBase::squeezyLifter->kMiddleTote));
	AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), CommandBase::squeezyLifter->kLastTote));

	AddSequential(new PlatformInOut(PlatformInOut::kIn));
	AddSequential(new SqueezyUpDown(CommandBase::squeezyLifter->isPracticeBot() ? GRABHEIGHTSCORINGPLATFORM_PRACTICE : GRABHEIGHTPLATFORM_COMPETITION, 6));
	AddSequential(new PushInOut(PushInOut::kOut));
	AddSequential(new WaitCommand(.2));//Lets pushers fully push
	AddSequential(new PushInOut(PushInOut::kIn));
	AddParallel(new SqueezyUpDown(CommandBase::squeezyLifter->isPracticeBot() ? HOLDHEIGHT_PRACTICE : HOLDHEIGHT_COMPETITION, CommandBase::squeezyLifter->kFirstTote));
}
