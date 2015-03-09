#include "SixToteStackAuto.h"

SixToteStackAuto::SixToteStackAuto()
{
	//	SetInterruptible(true);
		printf("Starting Squeezy Default \n");
		AddSequential(new PushInOut(PushInOut::kIn));
		AddSequential(new PlatformInOut(PlatformInOut::kOut));
		AddSequential(new WaitCommand(2));

		//First Tote
		AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), 0));

		AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), 1));
		AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), 2));
		AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), 3));
		AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), 4));
		AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), 5));
		AddSequential(new PlatformInOut(PlatformInOut::kIn));
		AddSequential(new WaitCommand(2));
		AddSequential(new SqueezyUpDown(CommandBase::squeezyLifter->isPracticeBot() ? GRABHEIGHTSCORINGPLATFORM_PRACTICE : GRABHEIGHTPLATFORM_COMPETITION, 6));
		AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kOpen));
		AddSequential(new PushInOut(PushInOut::kOut));
		AddSequential(new WaitCommand(.2));
		AddSequential(new PushInOut(PushInOut::kIn));


}
