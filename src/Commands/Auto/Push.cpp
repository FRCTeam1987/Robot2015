#include "Push.h"
#include "../Pusher/PushInOut.h"

Push::Push()
{
	AddSequential(new PushInOut(PushInOut::kOut));
	WaitCommand(1);
	AddSequential(new PushInOut(PushInOut::kIn));
}
