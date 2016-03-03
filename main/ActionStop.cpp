#include "ActionStop.h"

ActionStop::ActionStop(double range) : ArAction("Stop")
{
	this->range = range;
		
}

ArActionDesired* ActionStop::fire(ArActionDesired currentDesired)
{

	// reset the actionDesired (must be done), to clear
	// its previous values.
	myDesired.reset();

	// if the sonar is null we can't do anything, so deactivate
	if (mySonar == NULL)
	{
		deactivate();
		return NULL;
	}

	return &myDesired;
}

void ActionStop::setRobot(ArRobot *robot)
{
	 ArAction::setRobot(robot);

	 mySonar = robot->findRangeDevice("sonar");
	if (mySonar == NULL)
	{
		 ArLog::log(ArLog::Terse, "actionExample: ActionTurn: Warning: I found no sonar, deactivating.");
		deactivate(); 
	}
}