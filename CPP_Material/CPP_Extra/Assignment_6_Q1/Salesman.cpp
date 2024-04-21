// #include "EmployeeException.h"
// #include "Employee.h"
// #include "Manager.h"
#include "Salesman.h"
#include <iostream>
using namespace std;

Salesman::Salesman() : Salesman(0, 0.0f, 0) {}

Salesman::Salesman(int id, float salary, int comm)
{
    this->id = id;
    this->salary = salary;
    this->comm = comm;
}

void Salesman::displayComm()
{
    cout << "Commission       : " << comm << endl;
}

void Salesman::acceptComm()
{
    cout << "Enter Commission : ";
    cin >> comm;
}

void Salesman::acceptData()
{
    Employee::acceptData();
    acceptComm();
}

void Salesman::displayData()
{
    Employee::displayData();
    displayComm();
}
