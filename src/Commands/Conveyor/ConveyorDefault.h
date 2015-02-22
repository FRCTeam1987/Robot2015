#ifndef ConveyorDefault_H
#define ConveyorDefault_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ConveyorDefault: public CommandBase
{
private:
	bool m_lifterWaitingForTote;
	bool m_exitWaitingForTote;

public:
	ConveyorDefault();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
