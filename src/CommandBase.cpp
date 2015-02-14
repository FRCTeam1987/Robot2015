#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveTrain* CommandBase::driveTrain = NULL;
SqueezyLifter* CommandBase::squeezyLifter = NULL;
Pusher* CommandBase::pusher = NULL;
Conveyor* CommandBase::conveyor = NULL;
OI* CommandBase::oi = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	driveTrain = new DriveTrain();
	squeezyLifter = new SqueezyLifter(driveTrain->IsPracticeBot());
	pusher = new Pusher(driveTrain->IsPracticeBot());
	conveyor = new Conveyor(driveTrain->IsPracticeBot());

	oi = new OI(driveTrain->IsPracticeBot());
}
