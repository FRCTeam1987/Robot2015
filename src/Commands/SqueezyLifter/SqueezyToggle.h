#ifndef SqueezyToggle_H
#define SqueezyToggle_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SqueezyToggle: public CommandBase
{
private:
	bool openClose;

public:
	SqueezyToggle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
