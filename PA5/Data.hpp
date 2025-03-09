#pragma once
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl; 

class Data
{
private:
    int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1 
    int serviceTime;   // Random time; varies between express and normal lanes; units in  
    // minutes 
    int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line 
    // before this customer; units in minutes 
    // This memory needs to be allocated on the heap! 

public: // Member functions 

    // consturctor 
    Data(int numbers = 1, int servTime = 0, int time = 0) // number is 1 because it alwuas atleast one person
        : customerNumber(numbers), serviceTime(servTime), totalTime(time) { }

    // copy constructor
    Data(const Data& existingPerson) // always use the class name when refrencing 
        : customerNumber(existingPerson.customerNumber),
        serviceTime(existingPerson.serviceTime), 
        totalTime(existingPerson.totalTime){}

    // deconstructor 
    ~Data(); 

    //getters
    int getCustomerNumber() {
        return customerNumber; 
    }

    int getServiceTime()
    {
        return serviceTime;
    }

    int getTotalTime()
    {
        return totalTime;
    }

    //setters 
    void setCustomerNumber(int custNum) {
        customerNumber = custNum; 
    }
    void setServiceTime(int servTime) {
        serviceTime = servTime;
    }
    void setTotalTime(int tolTime) {
        totalTime = tolTime;
    }
}; 


void runSimulation(int simulationTime);

