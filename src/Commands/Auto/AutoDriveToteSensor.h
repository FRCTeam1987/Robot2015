#ifndef AutoDriveToteSensor_H
#define AutoDriveToteSensor_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoDriveToteSensor: public CommandBase
{
private:
	float m_speed;
	float m_maxDistance;
	float kP;

public:
	AutoDriveToteSensor(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
