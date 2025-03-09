#include "Queue.hpp"




bool Queue::isEmpty()
{
	return this->pHead == nullptr && this->pTail == nullptr;
}


bool Queue::enqueue(const Data& newData)// switched it back to a refrence 
{
	QueueNode* pMem = new QueueNode(newData); // creating a new node
	bool success = false;

	if (pMem != nullptr)
	{
		// allcocatign space on heap succeffuly 
		if (this->pHead == nullptr)
		{
			// empty q
			this->pHead = this->pTail = pMem;
		}
		else {
			this->pTail->setNextptr(pMem);
			this->pTail = pMem;
		}
		success = true; 
	}

	return success;
}


Data Queue::dequeue()
{
	// made a call to the data class 
	Data data = this->pHead->getData();
	QueueNode* pTemp = this->pHead; // making a tempuary variable that 
	//refres to a node that is deleted 
	
	if (this->pHead == this->pTail)
	{
		this->pTail = nullptr; // sets one node in queue
	}

	this->pHead = this->pHead->getNext(); 

	delete pTemp; // deletes the node 
	
	cout << "finished deleting the node: " << endl; 
	return data; 
}

void Queue::destroyQue()
{

	while (!isEmpty())
	{
		Data pTemp = dequeue();	// dont know if i need Data pTemp
		// im currenlty storing all deleted files into a temporary variable
	}
}
Queue::~Queue()
{
	destroyQue();
}

void Queue::printQueue() 
{
	QueueNode* current = pHead; 
	if (current == nullptr)
	{
		cout << "Queue is empty" << endl;
	}

	while (current != nullptr)
	{
		cout << "customer number: "<< current->getData().getCustomerNumber() << endl;
		cout << "service time: " << current->getData().getServiceTime() << endl;
		cout << "total time: " << current->getData().getTotalTime() << endl;

		current = current->getNext(); //  the head eof the node to the next node 
	}
}
