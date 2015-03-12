#ifndef DriveStraight_H
#define DriveStraight_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DriveStraight: public CommandBase

{
private:
	float m_distance;
	float m_speed;
	float kP;

public:
	DriveStraight(float distance, float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
