#include "QueueNode.hpp"



class Queue // this is going to be the queue itself i believe 
{
private:
    QueueNode* pHead, * pTail;

	void printQueue(); // this will print data that

public: // Member functions 

	Queue() { pHead = pTail = nullptr; } // constructor 
	
	~Queue(); // deconstructor

	bool isEmpty();

	bool enqueue(const Data& newData); // changed it back to a refrence  
	Data dequeue();

	void destroyQue(); 

	// getters 
	QueueNode* getPhead();
	QueueNode* getPtail();




	friend class TestQueue; // friend gives acces to all of the Queue class to the testcases class. 

};



