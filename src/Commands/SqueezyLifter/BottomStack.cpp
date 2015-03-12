#include "BottomStack.h"
#include "SqueezyUpDown.h"
#include "../../Robotmap.h"
#include "SqueezyOpenClose.h"

BottomStack::BottomStack(bool isPracticeBot)
{
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

	AddSequential(new SqueezyUpDown(PlaceHeight, 0));
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kOpen));
	AddSequential(new SqueezyUpDown(GrabHeight, 1));
	AddSequential(new SqueezyOpenClose(SqueezyOpenClose::kClose));
	AddSequential(new SqueezyUpDown(HoldHeight, 1));
}
