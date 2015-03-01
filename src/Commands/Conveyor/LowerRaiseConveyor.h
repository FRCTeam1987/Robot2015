#ifndef LowerRaiseConveyor_H
#define LowerRaiseConveyor_H

#include "../../CommandBase.h"
#include "WPILib.h"

class LowerRaiseConveyor: public CommandBase
{
public:
	enum WinchDirection {
		kRaise, kLower
	};

private:
	WinchDirection m_direction;

public:
	LowerRaiseConveyor(WinchDirection direction, double runTime);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
