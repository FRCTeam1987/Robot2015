#ifndef IncrementToteCount_H
#define IncrementToteCount_H

#include "../../CommandBase.h"
#include "WPILib.h"

class IncrementToteCount: public CommandBase
{
public:
	IncrementToteCount();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
