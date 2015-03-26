#include "StartFullyAuto.h"
#include "SqueezyLifter/SqueezyDefault.h"
#include "Conveyor/ConveyorDefault.h"
#include "Conveyor/NewConveyorDefault.h"

/**
 * Runs Teleop Auto
 */
StartFullyAuto::StartFullyAuto()
{
	AddParallel(new SqueezyDefault);
	AddParallel(new NewConveyorDefault);
}
