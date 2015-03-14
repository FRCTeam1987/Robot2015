#include "LowerConveyorWait.h"
#include "../Conveyor/LowerRaiseConveyor.h"

LowerConveyorWait::LowerConveyorWait()
{
	AddSequential(new WaitCommand(7));
	AddSequential(new LowerRaiseConveyor(LowerRaiseConveyor::kLower, 3.25));
}
