#ifndef SetPause_H
#define SetPause_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SetPause: public CommandBase
{
public:
	SetPause();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
