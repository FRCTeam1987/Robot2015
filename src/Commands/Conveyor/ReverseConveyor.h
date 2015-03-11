#ifndef ReverseConveyor_H
#define ReverseConveyor_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ReverseConveyor: public CommandBase
{
private:
	bool m_On;
public:
	ReverseConveyor(bool On);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
