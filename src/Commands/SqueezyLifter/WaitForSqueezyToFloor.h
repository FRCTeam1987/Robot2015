#ifndef WaitForSqueezyToFloor_H
#define WaitForSqueezyToFloor_H

#include "../../CommandBase.h"
#include "WPILib.h"

class WaitForSqueezyToFloor: public CommandBase
{
public:
	WaitForSqueezyToFloor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
