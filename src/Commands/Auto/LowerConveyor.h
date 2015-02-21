#ifndef LowerConveyor_H
#define LowerConveyor_H

#include "../../CommandBase.h"
#include "WPILib.h"

class LowerConveyor: public CommandBase
{
public:
	LowerConveyor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
