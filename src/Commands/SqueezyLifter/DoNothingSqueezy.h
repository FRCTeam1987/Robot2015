#ifndef DoNothingSqueezy_H
#define DoNothingSqueezy_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DoNothingSqueezy: public CommandBase
{
public:
	DoNothingSqueezy();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
