#include "testQueue.hpp"

void TestQueue::testEnqueueOnEmpty()
{
	Queue q; // allows access enqueue
	Data expected;  // allows acces to customers, total time, adn service time. 

	bool success = q.enqueue(expected); // we want to capture what enqueue returns 

	if (success == false)
	{
		cout << "enqueue has failed" << endl; 
	}

	if (q.pHead != q.pTail) {
		cout << "phead does not equal ptail" << endl; 
	}

	if (q.pHead == nullptr)
	{
		cout << " phead equals null" << endl; 
		return; // this is preventing from my program from crashing 
	}
	
	Data actual = q.pHead->getData(); 

	if (actual.getServiceTime() != expected.getServiceTime())
	{
		cout << "service is wrong" << endl; 
	}

	if (actual.getCustomerNumber() != expected.getCustomerNumber())
	{
		cout << "customer number wrong" << endl;
	}

	if (actual.getTotalTime() != expected.getTotalTime())
	{
		cout << "total time is wrong" << endl;
	}
}

void TestQueue::testEnqueueWithOneElement()
{

	Queue q; // allows access to the enqueue
	Data first; // allows access to customers and time.
	Data second; 

	bool success = q.enqueue(first);

	if (success == false)
	{
		cout << " first enqueue has failed" << endl; 
	}
	success = q.enqueue(second); // this is updating  success 

	if (success == false)
	{
		cout << "second enqueue has failed" << endl; 
	}

	if (q.pHead == nullptr)
	{
		cout << " head of the node is null" << endl; 
	}

	if (q.pHead == q.pTail)
	{
		cout << "pHead and pTail shouldn't equal eachother" << endl;
	}

	Data firstElement = q.pHead->getData();

	if (firstElement.getCustomerNumber() != first.getCustomerNumber())
	{
		cout << "First element: customer numbers do not match" << endl; 
	}

	if (firstElement.getServiceTime() != first.getServiceTime())
	{
		cout << " First Element: service time do not match" << endl; 
	}

	if (firstElement.getTotalTime() != first.getTotalTime())
	{
		cout << "First element: total times do not match" << endl;
	}

	Data secondElement = q.pHead->getData();

	if (secondElement.getCustomerNumber() != second.getCustomerNumber())
	{
		cout << "Second elements: cusotmer numbers do not match" << endl;
	}

	if (secondElement.getServiceTime() != second.getServiceTime())
	{
		cout << "Second elements: service times do not match" << endl;
	}

	if (secondElement.getTotalTime() != second.getTotalTime())
	{
		cout << "second elements: total time does not match" << endl; 
	}
}

void TestQueue::testDequeueWithOneElement()
{
	Queue d;
	Data firstNode;
	Data secondNode;

	


}

void TestQueue::testDequeueWithTwoElement()
{
	Queue l;
	Data fistNode;
	Data secondNode;
	Data thirdNode; 



}

void TestQueue::testSimulation()
{


}



