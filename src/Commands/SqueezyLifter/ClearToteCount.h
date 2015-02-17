#ifndef ClearToteCount_H
#define ClearToteCount_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ClearToteCount: public CommandBase
{
public:
	ClearToteCount();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
