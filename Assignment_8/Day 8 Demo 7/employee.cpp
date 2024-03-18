#include "person.h"
#include "employee.h"


void Employee::acceptData()
{
    cout << "Enter empid - ";
    cin >> empid;
    Person::acceptData();
    cout << "Enter Salary - ";
    cin >> salary;
}

void Employee::displayData()
{
    cout << "Empid - " << empid << endl;
    Person::displayData();
    cout << "Salary - " << salary << endl;
}
