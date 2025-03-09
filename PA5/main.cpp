#include "Queue.hpp"


int main(void)
{
	int simulationTime = 0; // this is the time that the simulation will run for
	cout << "Please enter the time you would like to run the simulation for: (in minutes) ";
	cin >> simulationTime; // getting the time from the user
	runSimulation(simulationTime);
 
}