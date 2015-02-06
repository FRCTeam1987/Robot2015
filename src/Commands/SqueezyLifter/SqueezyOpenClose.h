#ifndef SqueezyOpenClose_H
#define SqueezyOpenClose_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SqueezyOpenClose: public CommandBase
{
public:
	enum SqueezyDirection {
		kOpen, kClose
	};

private:
	SqueezyDirection m_direction;

public:
	SqueezyOpenClose(SqueezyDirection direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
