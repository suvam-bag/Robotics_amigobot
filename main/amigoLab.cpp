#include <stdio.h>
#include "Aria.h"
#include "AmigoBot.h"
#include "ActionStop.h"
#include <iostream>
using namespace std;


// Function Prototypes
//void thereAndBackAgain(ArRobot*);
//void aroundTheBlock(ArRobot*, int);
void sonar_stop(ArRobot* );
//void wander(ArRobot* );


int main( int argc, char** argv )
{
	Aria::init();

	// Create a New amigoBot Object
	// Param 1 - Some Name
	// Param 2 - Connection Type (AmigoBot::REMOTE, AmigoBot::SERIAL,AmigoBot::SIMULATOR)
	// Param 3 - Special Connection Param (IP, COM, PORT)

	//AmigoBot* amigoBot = new AmigoBot("C",AmigoBot::REMOTE, "amigo1.rit.edu");	
	//AmigoBot* amigoBot = new AmigoBot("A",AmigoBot::SERIAL,"COM");
	AmigoBot* amigoBot = new AmigoBot("E",AmigoBot::SIMULATOR,"8101");

	// Create the Actions
	ArActionStallRecover recover;
	ActionStop actionStop(1000); 

	// Create Devices
	ArSonarDevice sonar;

	// Attach Actions
	amigoBot->getRobot()->addRangeDevice(&sonar);
	amigoBot->getRobot()->addAction(&recover,100);
	amigoBot->getRobot()->addAction(&actionStop,50);

	// Start the robot
	amigoBot->getRobot()->enableMotors();
	amigoBot->getRobot()->runAsync(true);

	// Pace the Robot Back and Forth
	/*for( int i = 1; i <6; i++)
	{
		thereAndBackAgain(amigoBot->getRobot());
	}*/

	
	// Pace the Robot Around in a Circle
	// For 10 times or until error is too great
	/*for( int i = 1; i <5; i++)
	{
		aroundTheBlock(amigoBot->getRobot(), 1);
	}*/
	

	// Collect Sonar Readings
	for (int i = 1; i < 2; i++)
	{
		sonar_stop(amigoBot->getRobot());
		
		ArUtil::sleep(500);
		getchar();
	//wander(amigoBot->getRobot());
	//getchar();
	}
	// Clean-Up Destroy the AmigoBot Object
	delete amigoBot;
	
	return 0;
}

void aroundTheBlock(ArRobot* robot, int iteration)
{
	//robot->runAsync(true); //Run in asynchronous mode 17
	robot->unlock(); //Lock robot during set up 18
	//robot->comInt(ArCommands::ENABLE, 1); //Turn on the motors 19	
	robot->setVel(200); //Set translational velocity to 200 mm/s
	ArUtil::sleep(4570);
	robot->setVel(0); //Set the robots "brakes"
	ArUtil::sleep(500);
	//ArUtil::sleep(2000);
	//robot->setRotVel(200); //Set rotational velocity to 20 degrees/s
	//robot->setVel2(200, 250); //Set left wheel speed at 200 mm/s
	//Set right wheel speed at 250 mm/s
	//robot->move(914); //Move 200 mm forwards

	//robot->setHeading(30); //90 degrees relative to start position


	robot->lock();
	robot->unlock();
	//robot->comInt(ArCommands::ENABLE, 1); //Turn on the motors 19	
	robot->setRotVel(43); //Set rotational velocity to 20 degrees/s
	ArUtil::sleep(2250);
	robot->setRotVel(0);
	ArUtil::sleep(500);
	//robot->setDeltaHeading(180); //180 degrees relative to current orientation
	robot->lock();
	robot->unlock();
	//robot->comInt(ArCommands::ENABLE, 1); //Turn on the motors 19
	//robot->move(200); //Move 200 mm forwards
	//robot->lock();
	//ArUtil::sleep(2000);
}

void thereAndBackAgain(ArRobot* robot)
{
	//robot->runAsync(true); //Run in asynchronous mode 17
	robot->unlock(); //Lock robot during set up 18
	//robot->comInt(ArCommands::ENABLE, 1); //Turn on the motors 19	
	robot->setVel(200); //Set translational velocity to 200 mm/s
	ArUtil::sleep(4570);
	robot->setVel(0); //Set the robots "brakes"
	//ArUtil::sleep(2000);
	//robot->setRotVel(200); //Set rotational velocity to 20 degrees/s
	//robot->setVel2(200, 250); //Set left wheel speed at 200 mm/s
	//Set right wheel speed at 250 mm/s
	//robot->move(914); //Move 200 mm forwards

	//robot->setHeading(30); //90 degrees relative to start position

	
	robot->lock();
	robot->unlock();
	//robot->comInt(ArCommands::ENABLE, 1); //Turn on the motors 19	
	robot->setRotVel(40); //Set rotational velocity to 20 degrees/s
	ArUtil::sleep(4500);
	robot->setRotVel(0);
	//robot->setDeltaHeading(180); //180 degrees relative to current orientation
	robot->lock();
	robot->unlock();
	//robot->comInt(ArCommands::ENABLE, 1); //Turn on the motors 19
	//robot->move(200); //Move 200 mm forwards
	//robot->lock();
	//ArUtil::sleep(2000);
}

void sonar_stop(ArRobot* robot)
{
	int numSonar; //Number of sonar on the robot
	int i; //Counter for looping
	//int j;
	numSonar = robot->getNumSonar(); //Get number of sonar
	ArSensorReading* sonarReading; //To hold each reading
	//for (j = 1; j < 6; j++)
	//{
	robot->setVel(200); //Set translational velocity to 200 mm/s
	for (;;)
	{
		for (i = 0; i < numSonar; i++) //Loop through sonar
	
		
		{
			sonarReading = robot->getSonarReading(i); //Get each sonar reading
			cout << "Sonar reading " << i << " = " << sonarReading->getRange()
				<< " Angle " << i << " = " << sonarReading->getSensorTh() << "\n";
			//getchar();

			if (sonarReading->getSensorTh() > -90 && sonarReading->getSensorTh() < 90 && sonarReading->getRange() < 500)

				robot->setVel(0);
		}
	}
			//<< " Angle " << i << " = " <<
			//printf("Sonar Reading", i, "=",sonarReading)
			//robot->unlock(); //Lock robot during set up 18
			//robot->comInt(ArCommands::ENABLE, 1); //Turn on the motors 19	

		//robot->setVel(200); //Set translational velocity to 200 mm/s
		//if (sonarReading[1] < 500)
		//{
			//robot->setRotVel(0);
		//}
		
	}

/*void wander(ArRobot* robot)
{
	int numSonar; //Number of sonar on the robot
	int i; //Counter for looping
	//int j;
	numSonar = robot->getNumSonar(); //Get number of sonar
	ArSensorReading* sonarReading; //To hold each reading
	//for (j = 1; j < 6; j++)
	//{
	
	for (;;)
	{
		robot->setVel(200); //Set translational velocity to 200 mm/s
		for (i = 0; i < numSonar; i++) //Loop through sonar
		{
			sonarReading = robot->getSonarReading(i); //Get each sonar reading
			cout << "Sonar reading " << i << " = " << sonarReading->getRange()
				<< " Angle " << i << " = " << sonarReading->getSensorTh() << "\n";
			//getchar();

			if (sonarReading->getSensorTh() < 0 && sonarReading->getSensorTh() > -42 && sonarReading->getRange() < 1000)
			{
				robot->setRotVel(43); //Set rotational velocity to 40 degrees/s
				ArUtil::sleep(1500);
				robot->setRotVel(0);
			}

			else if (sonarReading->getSensorTh() > 0 && sonarReading->getSensorTh() < 42 && sonarReading->getRange() < 1000)
			{
				robot->setRotVel(-43);
				ArUtil::sleep(1500);
				robot->setRotVel(0);
			}

			else
			{
				robot->setVel(200);
			}






			/*switch ()
			{
			case 'A':
			case 'a':
			{
			if (sonarReading->getSensorTh() > -16 && sonarReading->getSensorTh() < 16 && sonarReading->getRange() < 500)
			robot->setRotVel(40); //Set rotational velocity to 40 degrees/s
			ArUtil::sleep(1000);
			robot->setRotVel(0);
			else
			robot->setVel(200);
			}
			case 'B':
			case 'b':
			{
			if (sonarReading->getSensorTh() > -40 && sonarReading->getSensorTh() < 40 && sonarReading->getRange() < 500)
			robot->setRotVel(90); //Set rotational velocity to 90 degrees/s
			ArUtil::sleep(1000);
			robot->setRotVel(0);
			else
			robot->setVel(200);
			}
			case 'C':
			case 'c':
			{
			if (sonarReading->getSensorTh() > -90 && sonarReading->getSensorTh() < 90 && sonarReading->getRange() < 500)

			robot->setVel(0);

			}
			default: robot->setVel->(200);

			}

			/*if (sonarReading->getSensorTh() > -90 && sonarReading->getSensorTh() < 90 && sonarReading->getRange() < 500)

	robot->setVel(0);
			

		}
	}
	
}*/

