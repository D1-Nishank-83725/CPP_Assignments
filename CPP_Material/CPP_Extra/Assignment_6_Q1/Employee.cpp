#include "EmployeeException.h"
#include "Employee.h"
// #include <iostream>
// using namespace std;


Employee::Employee()
{
    id = 1;
    salary = 0.0;
}

Employee::Employee(int id, float salary)
{
    this->id = id;
    this->salary = salary;
}

int Employee::getId()
{
    return id;
}

float Employee::getSalary()
{
    return salary;
}

void Employee::setId(int id)
{
    this->id = id;
}

void Employee::setSalary(float salary)
{
    this->salary = salary;
}

void Employee::acceptData()
{
    cout << "Enter ID    : ";
    cin >> id;

    cout << "Enter Salary: ";
    cin >> salary;
    if (salary < 0)
    {
        throw EmployeeException("Salary cannot be less than 0");
    }
}

void Employee::displayData()
{
    cout << "ID              : " << id << endl;
    cout << "Salary          : " << salary << endl;
}

// Important Step: Because as we try to delete the manager or salesperson class
Employee::~Employee()
{
}
