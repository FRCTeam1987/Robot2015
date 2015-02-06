#ifndef SqueezyUpDown_H
#define SqueezyUpDown_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SqueezyUpDown: public CommandBase
{
private:
	int16_t m_goalHeight;
	int16_t m_initialHeight;

public:
	SqueezyUpDown(int16_t setHeight);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
