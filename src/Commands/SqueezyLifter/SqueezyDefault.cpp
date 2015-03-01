#include "SqueezyDefault.h"

SqueezyDefault::SqueezyDefault()
{
//	SetInterruptible(true);
	//First Tote
#if 1
	AddSequential(new SqueezyUpDown(CommandBase::squeezyLifter->isPracticeBot() ? HOLDHEIGHT_PRACTICE : HOLDHEIGHT_COMPETITION));
	AddSequential(new WaitForToteSensor());
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kOpen));
	AddSequential(new SqueezyUpDown(CommandBase::squeezyLifter->isPracticeBot() ? GRABHEIGHTCONVEYORPLATFORM_PRACTICE : GRABHEIGHTFLOOR_COMPETITION)); //change to conveyor platform height
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kClose));
//	AddSequential(new TakeABreak());
	AddSequential(new SqueezyUpDown(CommandBase::squeezyLifter->isPracticeBot() ? HOLDHEIGHT_PRACTICE : HOLDHEIGHT_COMPETITION));
	AddSequential(new IncrementToteCount());
	//Totes  2-5
#endif
	AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot()));
#if 1
	AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot()));
	AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot()));
	AddSequential(new LiftTote(CommandBase::squeezyLifter->isPracticeBot()));
	AddSequential(new WaitCommand(987432587943)); //Will be wait for platform to retract
#endif
}
