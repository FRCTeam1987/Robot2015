//This Is An Untested Command

#include "AutoThreeTote.h"
#include "DriveStraight.h"
#include "AutoDriveToteSensor.h"
#include "../SqueezyLifter/LiftTote.h"
#include "../SqueezyLifter/SqueezyUpDown.h"
#include "../SqueezyLifter/SqueezyOpenClose.h"
#include "AutoTurn.h"
#include "../../RobotMap.h"

AutoThreeTote::AutoThreeTote(bool isPracticeBot)
{
	AddSequential(new AutoDriveToteSensor(0.5));
	AddSequential(new LiftTote(isPracticeBot, 0));
	AddSequential(new AutoDriveToteSensor(0.5));
	AddSequential(new LiftTote(isPracticeBot, 1));
	AddSequential(new AutoDriveToteSensor(0.5));
	AddSequential(new LiftTote(isPracticeBot, 2));
	AddSequential(new AutoTurn(0.5, 90));
	AddSequential(new DriveStraight(60, .5));
	AddSequential(new SqueezyUpDown(isPracticeBot ? GRABHEIGHTFLOOR_PRACTICE : GRABHEIGHTFLOOR_COMPETITION, 0));
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kOpen));
	AddSequential(new DriveStraight(-60, .5));
}

