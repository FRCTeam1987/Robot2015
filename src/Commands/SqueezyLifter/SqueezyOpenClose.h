#ifndef SqueezyOpenClose_H
#define SqueezyOpenClose_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SqueezyOpenClose: public CommandBase
{
private:
	bool m_open;

public:
	SqueezyOpenClose(bool input);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
