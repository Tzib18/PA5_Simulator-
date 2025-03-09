#pragma once
#include "Queue.hpp" 

// test cases never need parameters 


class TestQueue
{
private:

public:

	void testEnqueueOnEmpty(); //  empty enque 

	void testEnqueueWithOneElement(); // enque with one node

	void testDequeueWithOneElement();// operation with one node 

	void testDequeueWithTwoElement(); // operation with two nodes
	
	// one test case that runs for 24 hours 
	void testSimulation();


};