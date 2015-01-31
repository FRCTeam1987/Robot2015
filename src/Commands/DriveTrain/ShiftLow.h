#ifndef SHIFTLOW_H
#define ShiftLow_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ShiftLow: public CommandBase
{
public:
	ShiftLow();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
