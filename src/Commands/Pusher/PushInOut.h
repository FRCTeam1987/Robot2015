#ifndef PushInOut_H
#define PushInOut_H

#include "../../CommandBase.h"
#include "WPILib.h"

class PushInOut: public CommandBase
{
public:
	enum PushDirection {
		kIn, kOut
	};

private:
	PushDirection m_pushDirection;

public:
	PushInOut(PushDirection direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
