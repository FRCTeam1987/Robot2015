#include "LiftTote.h"
#include "SqueezyOpenClose.h"
#include "SqueezyUpDown.h"
#include "WaitForToteSensor.h"
#include "IncrementToteCount.h"
#include "TakeABreak.h"
#include "../../RobotMap.h"

/**
 * Lifts a single tote to hold height
 * @param isPracticeBot true if practice robot
 * @param toteNumber the number of totes in a stack
 */
LiftTote::LiftTote(bool isPracticeBot, int toteNumber)
{
	AddSequential(new SqueezyUpDown(isPracticeBot ? HOLDHEIGHT_PRACTICE : HOLDHEIGHT_COMPETITION, toteNumber));
	AddSequential(new WaitForToteSensor());
	AddSequential(new SqueezyUpDown(isPracticeBot ? GRABHEIGHTCONVEYORPLATFORM_PRACTICE : GRABHEIGHTCONVEYORPLATFORM_COMPETITION, toteNumber));
	AddSequential(new TakeABreak());
	AddSequential(new IncrementToteCount());
	if(toteNumber < 5){
		AddSequential(new SqueezyUpDown(isPracticeBot ? HOLDHEIGHT_PRACTICE : HOLDHEIGHT_COMPETITION, toteNumber));
	}else{//We don't need to go all the way up because it is the last tote in the stack
		AddSequential(new SqueezyUpDown(isPracticeBot ? PLATFORMHOLDHEIGHT_PRACTICE : PLATFORMHOLDHEIGHT_COMPETITION, toteNumber));
	}
}
