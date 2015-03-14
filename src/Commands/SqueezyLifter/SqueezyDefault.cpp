#include "SqueezyDefault.h"

/**
 * Stack 5 stacks of totes
 */
SqueezyDefault::SqueezyDefault()
{
	//Change this for different heights
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

}
