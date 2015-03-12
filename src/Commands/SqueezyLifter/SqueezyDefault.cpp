#include "SqueezyDefault.h"

/**
 * Stack 5 stacks of totes
 */
SqueezyDefault::SqueezyDefault()
{
	AddSequential(new SixToteStackAuto());
	AddSequential(new SixToteStackAuto());
	AddSequential(new SixToteStackAuto());
	AddSequential(new SixToteStackAuto());
	AddSequential(new SixToteStackAuto());
}
