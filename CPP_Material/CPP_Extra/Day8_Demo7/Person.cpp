#include "Person.h"

void Person::acceptData()
{
    cout << "Enter Name: ";
    cin >> name;
}

void Person::displayData()
{
    cout << "Name: " << name << endl;
}

string Person::getName()
{
    return this->name;
}

void Person::setName(string name)
{
    this->name = name;
}
