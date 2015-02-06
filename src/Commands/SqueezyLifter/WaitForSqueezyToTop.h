#ifndef WaitForSqueezyToTop_H
#define WaitForSqueezyToTop_H

#include "../../CommandBase.h"
#include "WPILib.h"

class WaitForSqueezyToTop: public CommandBase
{
public:
	WaitForSqueezyToTop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
