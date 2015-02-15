#include "BottomStack.h"
#include "SqueezyUpDown.h"
#include "../../Robotmap.h"
#include "SqueezyOpenClose.h"

BottomStack::BottomStack(bool isPracticeBot)
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

	int GrabHeight, HoldHeight, PlaceHeight;
	if(isPracticeBot)
	{
		GrabHeight = GRABHEIGHTFLOOR_PRACTICE;
		HoldHeight = HOLDHEIGHT_PRACTICE;
		PlaceHeight = PLACEHEIGHT_PRACTICE;
	}
	else
	{
		GrabHeight = GRABHEIGHTFLOOR_COMPETITION;
		HoldHeight = HOLDHEIGHT_COMPETITION;
		PlaceHeight = PLACEHEIGHT_COMPETITION;
	}

	AddSequential(new SqueezyUpDown(PlaceHeight));
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kOpen));
	AddSequential(new SqueezyUpDown(GrabHeight));
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kClose));
	AddSequential(new SqueezyUpDown(HoldHeight));
}
