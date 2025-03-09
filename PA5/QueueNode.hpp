#pragma once
#include "Data.hpp"



class QueueNode
{
private:
    Data* pData;    // The memory for Data will need to be allocated on the heap as well! 
    QueueNode* pNext;

public: // Member functions 

    // constructors
	QueueNode(const Data& data) : pData(new Data(data)), pNext(nullptr) {} // changed the parameter to a pointer and initialized members


	// copy constructor
	QueueNode operator=(const QueueNode& rhs)
	{
		if (this != &rhs)
		{
			delete this->pData; // free the existing data
			this->pData = new Data(*rhs.pData);
			this->pNext = rhs.pNext; 
		}
		return *this; 
	}

	// deconstructor
	~QueueNode() { delete pData; }

    //getters
	Data& getData() const { return *pData; } // return reference to Data
	QueueNode* getNext() const { return pNext; }

	//setters
	void setNextptr(QueueNode* newNextptr) 
	{ pNext = newNextptr; }

	void setData(const Data& newData)
	{ *pData = newData; }

	friend class TestQueue; 
};

// create a secondary que so wehn you deque add it to the next que to insert it 
// back into the queue 

// make a printing funciton that will prints out eveyr 10 minutes 
