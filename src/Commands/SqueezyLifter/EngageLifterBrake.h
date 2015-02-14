#ifndef EngageLifterBrake_H
#define EngageLifterBrake_H

#include "../../CommandBase.h"
#include "WPILib.h"

class EngageLifterBrake: public CommandBase
{
public:
	EngageLifterBrake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
