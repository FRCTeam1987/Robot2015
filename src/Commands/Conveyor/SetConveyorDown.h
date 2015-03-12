#ifndef SetConveyorDown_H
#define SetConveyorDown_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SetConveyorDown: public CommandBase
{
public:
	SetConveyorDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
