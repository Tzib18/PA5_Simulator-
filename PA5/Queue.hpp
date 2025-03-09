#include "QueueNode.hpp"



class Queue // this is going to be the queue itself i believe 
{
private:
    QueueNode* pHead, * pTail;


public: // Member functions 

	Queue() { pHead = pTail = nullptr; } // constructor 
	
	~Queue(); // deconstructor

	bool isEmpty();

	bool enqueue(const Data& newData); // changed it back to a refrence  
	Data dequeue();

	void destroyQue(); 

	// getters 
	QueueNode* getPhead() { return pHead; }
	QueueNode* getPtail() { return pTail;  }

	void printQueue(); // this will print data that



	friend class TestQueue; // friend gives acces to all of the Queue class to the testcases class. 

};



