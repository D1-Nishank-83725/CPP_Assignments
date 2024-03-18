#ifndef PERSON_H
#define PERSON_H


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person
{
private:
    string name;

public:
    virtual void acceptData();
    virtual void displayData();
    
};

#endif