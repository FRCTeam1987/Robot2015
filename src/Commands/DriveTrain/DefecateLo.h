#ifndef DefecateLo_H
#define DefecateLo_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DefecateLo: public CommandBase
{
public:
	DefecateLo();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
