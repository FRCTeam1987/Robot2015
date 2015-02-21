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
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.

	AddSequential(new AutoDriveToteSensor(0.5));
	AddSequential(new LiftTote(isPracticeBot));
	AddSequential(new AutoDriveToteSensor(0.5));
	AddSequential(new LiftTote(isPracticeBot));
	AddSequential(new AutoDriveToteSensor(0.5));
	AddSequential(new LiftTote(isPracticeBot));
	AddSequential(new AutoTurn(0.5, 90));
	AddSequential(new DriveStraight(60, .5));
	AddSequential(new SqueezyUpDown(isPracticeBot ? GRABHEIGHTFLOOR_PRACTICE : GRABHEIGHTFLOOR_COMPETITION));
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kOpen));
	AddSequential(new DriveStraight(-60, .5));
}

