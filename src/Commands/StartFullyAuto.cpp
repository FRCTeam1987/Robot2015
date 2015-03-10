#include "StartFullyAuto.h"
#include "SqueezyLifter/SqueezyDefault.h"
#include "Conveyor/ConveyorDefault.h"

StartFullyAuto::StartFullyAuto()
{
	AddParallel(new SqueezyDefault);
	AddParallel(new ConveyorDefault);
}
