#include "SqueezyDefault.h"

/**
 * Stack 5 stacks of totes
 */
SqueezyDefault::SqueezyDefault()
{
//	AddSequential(new PlatformInOut(PlatformInOut::kOut));
	//Change this for different heights
	AddSequential(new FourStackAuto());
	AddSequential(new FourStackAuto());
	AddSequential(new FourStackAuto());
	AddSequential(new FourStackAuto());
	AddSequential(new FourStackAuto());
	AddSequential(new FourStackAuto());


//	AddSequential(new FiveStackAuto());
//	AddSequential(new FiveStackAuto());
//	AddSequential(new FiveStackAuto());
//	AddSequential(new FiveStackAuto());
//	AddSequential(new FiveStackAuto());

//	AddSequential(new SixToteStackAuto());
//	AddSequential(new SixToteStackAuto());
//	AddSequential(new SixToteStackAuto());
//	AddSequential(new SixToteStackAuto());
//	AddSequential(new SixToteStackAuto());

//	AddSequential(new OneToteStackAuto());
//	AddSequential(new TwoToteStackAuto());
//	AddSequential(new ThreeToteStackAuto());
//	AddSequential(new FourStackAuto());
//	AddSequential(new FiveStackAuto());

//	AddSequential(new FourStackAuto());
//	AddSequential(new FiveStackAuto());
//	AddSequential(new SixToteStackAuto());
//	AddSequential(new FiveStackAuto());
//	AddSequential(new FourStackAuto());

}
