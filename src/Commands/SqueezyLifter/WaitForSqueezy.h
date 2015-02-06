#ifndef WaitForSqueezy_H
#define WaitForSqueezy_H

#include "../../CommandBase.h"
#include "WPILib.h"

class WaitForSqueezy: public CommandBase
{
public:
	WaitForSqueezy();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
