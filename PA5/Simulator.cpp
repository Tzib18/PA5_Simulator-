
// this is my simulaiton 
#include "Queue.hpp"


void runSimulation(int simulationTime)
{
	srand(time(0)); // seed the random number generator

	
	Queue expressLane;
	Queue normalLane;

	int elapsedTime = 0;
	int cusNumber = 1; // customer is always one 

	int newExpressArrival = rand() % 5 + 1; // getting minutes anywhere from 1 to 5 minutes
	int newNormalArrival = rand() % 6 + 3;  // getting minutes anywhere from 3- 8 minutes; 

	// the loop for the simulation: each time it iterates its one minutes
	while (elapsedTime < simulationTime)
	{
		// checking if the elapsed time is pottetnially equal to the express arrival time 
		if (elapsedTime == newExpressArrival)
		{
			int expressServiceTime = rand() % 5 + 1;  // service time 1-5 minutes; for both lanes 
			int totalTime = expressServiceTime; // to get the total time for the customers service
			// and arrival time 
				// newCustomer will have customer number, service and total tiem within it 
			
			Data newCustomer(cusNumber++, expressServiceTime, totalTime); // new customer calls the data class 
			// and has the customer # that it calls and icrements, along with service 
			// time and the total time service and arrival time.

			expressLane.enqueue(newCustomer); // adding the customer to the express lane
			cout << "ExpressLaneCustomer number: " << newCustomer.getCustomerNumber()// gets the customer as an object 
				<< " has arrived at the express lane at: " << elapsedTime << " minutes" << endl;

			newExpressArrival = elapsedTime + (rand() % 5 + 1); // getting the next arrival time for the express lane
		}

		// checking if the elapsed time pottentoially equal the normal lane arrivals time 
		if (elapsedTime == newNormalArrival)
		{
			int normalServiceTime = rand() % 6 + 3; // service time 3-8 minutes; for both lanes
			int totalTime = normalServiceTime; // to get the total time for the customers service

			Data newCustomer(cusNumber++, normalServiceTime, totalTime); // new customer calls the data class and 
			// gets the customer number, service time, and total time for the customer
		

			normalLane.enqueue(newCustomer); // adding the customer to the normal lane
			cout << "Normal Lane Customer number: " << newCustomer.getCustomerNumber() // gets the customer number as a object
				// so i can modify the item instead of a copy. 
				<< " has arrived at the normal lane at: " << elapsedTime << " minutes" << endl;

			newNormalArrival = elapsedTime + (rand() % 6 + 3); // getting the next arrival time for the normal lane
		}
		
		if(!expressLane.isEmpty())
		{
			// getting the first customer in the express lane
			Data& expressCustomer = expressLane.getPhead()->getData();
			
			if (expressCustomer.getServiceTime() + expressCustomer.getTotalTime())
			{
				expressCustomer = expressLane.dequeue(); // removing the customer from the express lane
				cout << "express lane customer number: " << expressCustomer.getCustomerNumber()
					<< " has left the express lane at: " << elapsedTime << " minutes" << endl;
				//delete leavingCustome; // deleting the customer from the heap
			}
		}

		if (!normalLane.isEmpty())
		{
			Data& normalCustomer = normalLane.getPhead()->getData(); // getting the first customer in the normal lane
			if (normalCustomer.getServiceTime() + normalCustomer.getTotalTime())
			{
				normalCustomer = normalLane.dequeue(); // removing the customer from the normal lane
				cout << "normal lane customer number: " << normalCustomer.getCustomerNumber()
					<< " has left the normal lane at: " << elapsedTime <<	 " minutes" << endl;
				//delete leavingCustomer; // deleting the customer from the heap

			}
		}
		// PRINTING OUT THE LINES EVERY 10 MINUTES
		if (elapsedTime % 10 == 0)
		{
			cout << "Express Queue Line at: " << elapsedTime << "Minutes: " << endl;
			expressLane.printQueue(); 


			cout << "Express Queue Line at: " << elapsedTime << "Minutes: " << endl; 
			normalLane.printQueue(); 
		} 


		elapsedTime++; // incrementing the elapsed time

	}

}