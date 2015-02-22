#ifndef RunConveyor_H
#define RunConveyor_H

#include "../../CommandBase.h"
#include "WPILib.h"

class RunConveyor: public CommandBase
{
private:
	bool m_On;

public:
	RunConveyor(bool On);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
