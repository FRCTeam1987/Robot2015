#include "SqueezyDefault.h"

SqueezyDefault::SqueezyDefault()
{
//	SetInterruptible(true);
	printf("Starting Squeezy Default \n");
	AddSequential(new PushInOut(PushInOut::kIn));
	printf("Made it to step 1! \n");
	AddSequential(new PlatformInOut(PlatformInOut::kOut));
	printf("Made it to step 2! \n");
	AddSequential(new WaitCommand(2));
	printf("Made it to step 3! \n");

	//First Tote
#if 0
	AddSequential(new SqueezyUpDown(CommandBase::squeezyLifter->isPracticeBot() ? HOLDHEIGHT_PRACTICE : HOLDHEIGHT_COMPETITION));
	AddSequential(new WaitForToteSensor());
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kOpen));
	AddSequential(new SqueezyUpDown(CommandBase::squeezyLifter->isPracticeBot() ? GRABHEIGHTCONVEYORPLATFORM_PRACTICE : GRABHEIGHTFLOOR_COMPETITION)); //change to conveyor platform height
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kClose));
	AddSequential(new TakeABreak());
	AddSequential(new SqueezyUpDown(CommandBase::squeezyLifter->isPracticeBot() ? HOLDHEIGHT_PRACTICE : HOLDHEIGHT_COMPETITION));
	AddSequential(new IncrementToteCount());
	//Totes  2-5
#else
	AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), 0));
	printf("Made it to step 4! \n");
#endif

	AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), 1));
	printf("Made it to step 5! \n");
	AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), 2));
	AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), 3));
	AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), 4));
	AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot(), 5));
	AddSequential(new PlatformInOut(PlatformInOut::kIn));
	AddSequential(new WaitCommand(2));
	AddSequential(new SqueezyUpDown(CommandBase::squeezyLifter->isPracticeBot() ? GRABHEIGHTSCORINGPLATFORM_PRACTICE : GRABHEIGHTPLATFORM_COMPETITION));
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kOpen));
	AddSequential(new PushInOut(PushInOut::kOut));
	AddSequential(new WaitCommand(.2));
	AddSequential(new PushInOut(PushInOut::kIn));

#if 0
	AddSequential(new PlatformInOut(PlatformInOut::kIn));
	AddSequential(new WaitCommand(1.0)); //Will be wait for platform to retract
	AddSequential(new SqueezyUpDown(CommandBase::squeezyLifter->isPracticeBot() ? GRABHEIGHTSCORINGPLATFORM_PRACTICE : GRABHEIGHTFLOOR_COMPETITION));
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kOpen));
	AddSequential(new PushInOut(PushInOut::kOut));
//	AddSequential(new WaitCommand(2.0));
	AddSequential(new PushInOut(PushInOut::kIn));
	AddSequential(new PlatformInOut(PlatformInOut::kOut));
	AddSequential(new SqueezyUpDown(CommandBase::squeezyLifter->isPracticeBot()? HOLDHEIGHT_PRACTICE : HOLDHEIGHT_COMPETITION));
#endif
}
