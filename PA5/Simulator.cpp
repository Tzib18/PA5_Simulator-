
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
		// this is the express lane implementation
		
		// checking if the elapsed time is potentially equal to the express arrival time 
		if (elapsedTime == newExpressArrival)
		{
			int expressServiceTime = rand() % 5 + 1;  // service time 1-5 minutes; for both lanes 
			int totalTime = expressServiceTime; // to get the total time for the customers service
			// and arrival time 
			
			// checking to see fi anybody is in line, if so 
			// start tracking the time.
			if (!expressLane.isEmpty())
			{
				totalTime += expressLane.getPtail()->getData().getTotalTime();
			}
				// newCustomer will have customer number, service and total tiem within it 

			Data newCustomer(cusNumber++, expressServiceTime, totalTime); // new customer calls the data class 
			// and has the customer # that it calls and icrements, along with service 
			// time and the total time service and arrival time.

			expressLane.enqueue(newCustomer); // adding the customer to the express lane
			cout << "Express Lane Customer number: "
				<< newCustomer.getCustomerNumber()// gets the customer as an object 
				<<endl
				<< " has arrived at the express lane at: "
				<< elapsedTime
				<< " minutes" << endl;

			newExpressArrival = elapsedTime + (rand() % 5 + 1); // getting the next arrival time for the express lane

		}
	
		if (!expressLane.isEmpty())
		{
			// getting the first customer in the express lane
			Data& expressCustomer = expressLane.getPhead()->getData();
			int updatedExpressServiceTime = expressCustomer.getCustomerNumber() - 1;
			expressCustomer.setServiceTime(updatedExpressServiceTime);

			if (updatedExpressServiceTime <= 0)
			{
				int expressLeavingCustomer = expressCustomer.getCustomerNumber();
				int expressCustTotalTime = expressCustomer.getTotalTime();
				expressCustomer = expressLane.dequeue(); // removing the customer from the express lane

				cout << "express lane customer number: " << expressLeavingCustomer << endl
					<< "has left the express lane at: " << elapsedTime << endl
					<< "customer total time in line:  " << expressCustTotalTime
					<< " minutes" << endl;
				cout << "customer: " << expressLeavingCustomer << " was here for a total of: "
					<< expressCustTotalTime << " minutes" << endl; 

			}
		    // this is the normal lane implementation

			// checking if the elapsed time potentially equal the normal lane arrivals time 
			if (elapsedTime == newNormalArrival)
			{
				int normalServiceTime = rand() % 6 + 3; // service time 3-8 minutes; for both lanes
				int totalTime = normalServiceTime; // to get the total time for the customers service

				// if thier is a cusotmer it starts getting the total time.
				if (!normalLane.isEmpty())
				{
					totalTime += normalLane.getPtail()->getData().getTotalTime();
				}

				Data newCustomer(cusNumber++, normalServiceTime, totalTime); // new customer calls the data class and 
				// gets the customer number, service time, and total time for the customer
				normalLane.enqueue(newCustomer); // adding the customer to the normal lane
				cout << "Normal Lane Customer number: "
					<< newCustomer.getCustomerNumber() // gets the customer number as a object
					<< endl// so i can modify the item instead of a copy. 
					<< "customer has arrived at the normal lane at: " << elapsedTime
					<< " minutes" << endl;

				newNormalArrival = elapsedTime + (rand() % 6 + 3); // getting the next arrival time for the normal lane
			}
		}

		if (!normalLane.isEmpty())
		{
			Data& normalCustomer = normalLane.getPhead()->getData(); // getting the first customer in the normal lane
			int updatedNormalServiceTime = normalCustomer.getServiceTime() - 1; 
			normalCustomer.setServiceTime(updatedNormalServiceTime);

			if (updatedNormalServiceTime <= 0)
			{
				int normalLeavingCustomer = normalCustomer.getCustomerNumber();
				int normalCustTotalTime = normalCustomer.getTotalTime();
				normalLane.dequeue(); 

				cout << "normal lane customer number: " << normalLeavingCustomer
					<<endl 
					<< "has left the normal lane at: " << elapsedTime << "minutes"<<endl 
					<<"Total time in line: "<< normalCustTotalTime<<" minutes" << endl;
				cout << "customer: " << normalLeavingCustomer << " was here for a total of: "
					<< updatedNormalServiceTime << " mintues" << endl; 

			}
		}

		// PRINTING OUT THE LINES EVERY 10 MINUTES
		if (elapsedTime % 10 == 0)
		{
			cout << "Express Queue Line at: " << elapsedTime << " Minutes: " << endl;
			expressLane.printQueue(); 


			cout << "Normal  Queue Line at: " << elapsedTime << " Minutes: " << endl; 
			normalLane.printQueue(); 
		} 

		elapsedTime++; // incrementing the elapsed time
	}
}