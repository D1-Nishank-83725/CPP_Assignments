#include "person.h"

void Person::acceptData()
{
    cout << "Enter name - ";
    cin >> name;
}

void Person::displayData()
{
    cout << "Name - " << name << endl;
}