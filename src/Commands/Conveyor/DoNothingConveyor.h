#ifndef DoNothingConveyor_H
#define DoNothingConveyor_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DoNothingConveyor: public CommandBase
{
public:
	DoNothingConveyor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
