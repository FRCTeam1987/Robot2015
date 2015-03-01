#ifndef PlatformInOut_H
#define PlatformInOut_H

#include "../../CommandBase.h"
#include "WPILib.h"

class PlatformInOut: public CommandBase
{
public:
	enum PlatformDirection {
		kIn, kOut
	};

private:
	PlatformDirection m_direction;

public:
	PlatformInOut(PlatformDirection direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
