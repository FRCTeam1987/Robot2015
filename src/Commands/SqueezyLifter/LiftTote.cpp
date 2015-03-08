#include "LiftTote.h"
#include "SqueezyOpenClose.h"
#include "SqueezyUpDown.h"
#include "WaitForToteSensor.h"
#include "IncrementToteCount.h"
#include "TakeABreak.h"
#include "../../RobotMap.h"

LiftTote::LiftTote(bool isPracticeBot, int toteNumber)
{
	AddSequential(new SqueezyUpDown(isPracticeBot ? HOLDHEIGHT_PRACTICE : HOLDHEIGHT_COMPETITION));
	AddSequential(new WaitForToteSensor());
	if (toteNumber > 0) {
		AddSequential(new SqueezyUpDown(isPracticeBot ? PLACEHEIGHTCONVEYORPLATFORM_PRACTICE : PLACEHEIGHTPLATFORM_COMPETITION));
	}
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kOpen));
	AddSequential(new SqueezyUpDown(isPracticeBot ? GRABHEIGHTCONVEYORPLATFORM_PRACTICE : GRABHEIGHTPLATFORM_COMPETITION));
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kClose));
	AddSequential(new TakeABreak());
	AddSequential(new IncrementToteCount());
	if(toteNumber < 5){
		AddSequential(new SqueezyUpDown(isPracticeBot ? HOLDHEIGHT_PRACTICE : HOLDHEIGHT_COMPETITION));
	}else{
		AddSequential(new SqueezyUpDown(isPracticeBot ? PLATFORMHOLDHEIGHT_PRACTICE : PLATFORMHOLDHEIGHT_COMPETITION));
	}
}
