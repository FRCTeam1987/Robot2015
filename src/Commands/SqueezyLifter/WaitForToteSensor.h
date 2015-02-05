#ifndef WaitForToteSensor_H
#define WaitForToteSensor_H

#include "../../CommandBase.h"
#include "WPILib.h"

class WaitForToteSensor: public CommandBase
{
public:
	WaitForToteSensor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
