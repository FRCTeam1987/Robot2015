#include "SqueezyDefault.h"

SqueezyDefault::SqueezyDefault()
{
	AddSequential(new SixToteStackAuto());
	AddSequential(new SixToteStackAuto());
	AddSequential(new SixToteStackAuto());
	AddSequential(new SixToteStackAuto());
	AddSequential(new SixToteStackAuto());
}
