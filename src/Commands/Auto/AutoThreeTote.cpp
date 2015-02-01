#include "AutoThreeTote.h"
#include "DriveStraight.h"
#include "AutoTurn.h"

AutoThreeTote::AutoThreeTote()
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

	AddSequential(new DriveStraight(24, .5));
	AddSequential(new WaitCommand(1));
	AddSequential(new DriveStraight(24, .5));
	AddSequential(new WaitCommand(2));
	AddSequential(new DriveStraight(24, .5));
	AddSequential(new WaitCommand(3));
	AddSequential(new AutoTurn(0.5, 90));
	AddSequential(new DriveStraight(24, .5));
}
