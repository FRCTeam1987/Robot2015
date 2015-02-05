#ifndef PushInOut_H
#define PushInOut_H

#include "../../CommandBase.h"
#include "WPILib.h"

class PushInOut: public CommandBase
{
private:
	bool m_push;

public:
	PushInOut(bool input);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
