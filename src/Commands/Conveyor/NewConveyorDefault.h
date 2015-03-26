#ifndef NewConveyorDefault_H
#define NewConveyorDefault_H

#include "../../CommandBase.h"
#include "WPILib.h"

class NewConveyorDefault: public CommandBase
{
private:
	int m_state;

public:
	NewConveyorDefault();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
