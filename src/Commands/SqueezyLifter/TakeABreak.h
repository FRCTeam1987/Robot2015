#ifndef TakeABreak_H
#define TakeABreak_H

#include "../../CommandBase.h"
#include "WPILib.h"

class TakeABreak: public CommandBase
{
public:
	TakeABreak();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
