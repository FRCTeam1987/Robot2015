#ifndef ReleaseLifterBrake_H
#define ReleaseLifterBrake_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ReleaseLifterBrake: public CommandBase
{
public:
	ReleaseLifterBrake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
