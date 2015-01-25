#ifndef ShiftHi_H
#define ShiftHi_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ShiftHi: public CommandBase
{
public:
	ShiftHi();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
