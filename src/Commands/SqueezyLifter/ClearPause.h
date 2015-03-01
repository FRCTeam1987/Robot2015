#ifndef ClearPause_H
#define ClearPause_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ClearPause: public CommandBase
{
public:
	ClearPause();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
