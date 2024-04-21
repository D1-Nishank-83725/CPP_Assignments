#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person
{
private:
    string name;

public:
    virtual void acceptData();
    virtual void displayData();
    string getName();
    void setName(string name);
};

#endif