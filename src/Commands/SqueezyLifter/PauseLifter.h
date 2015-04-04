#ifndef PauseLifter_H
#define PauseLifter_H

#include "../../CommandBase.h"
#include "WPILib.h"

class PauseLifter: public CommandBase
{
public:
	PauseLifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
