/**
 *	FileName:		ActionStop.h
 *	Author:			Ryan M. Bowen
 *	Date:			09/28/09
 *
 *	Description:	Header File for ActionStop Class 
 *					Use to be attached to the AmigoBot
 */
#ifndef ACTIONSTOP_H
#define ACTIONSTOP_H

#include "Aria.h"

class ActionStop : public ArAction
{
public:

	ActionStop( double range );

	virtual ~ActionStop(void) {};

	virtual ArActionDesired *fire( ArActionDesired currentDesired);

	virtual void setRobot(ArRobot* robot);

protected:

	ArRangeDevice *mySonar;

	ArActionDesired myDesired;

	double range;

};
#endif;