#include "LiftTote.h"
#include "SqueezyOpenClose.h"
#include "SqueezyUpDown.h"
#include "WaitForToteSensor.h"
#include "IncrementToteCount.h"
#include "TakeABreak.h"
#include "../../RobotMap.h"

LiftTote::LiftTote(bool isPracticeBot)
{
	AddSequential(new SqueezyUpDown(isPracticeBot ? HOLDHEIGHT_PRACTICE : HOLDHEIGHT_COMPETITION));
	AddSequential(new WaitForToteSensor());
	AddSequential(new SqueezyUpDown(isPracticeBot ? PLACEHEIGHTCONVEYORPLATFORM_PRACTICE : PLACEHEIGHTPLATFORM_COMPETITION));
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kOpen));
#if 1
	AddSequential(new SqueezyUpDown(isPracticeBot ? GRABHEIGHTCONVEYORPLATFORM_PRACTICE : GRABHEIGHTPLATFORM_COMPETITION));
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kClose));
	AddSequential(new TakeABreak());
	AddSequential(new IncrementToteCount());
	AddSequential(new SqueezyUpDown(isPracticeBot ? HOLDHEIGHT_PRACTICE : HOLDHEIGHT_COMPETITION));
#endif
}
