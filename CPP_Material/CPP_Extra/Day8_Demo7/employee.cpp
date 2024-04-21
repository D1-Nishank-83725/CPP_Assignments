#include "Person.h"
#include "Employee.h"

int Employee::getEmpid()
{
    return this->empid;
}

void Employee::setEmpid(int empid)
{
    this->empid = empid;
}

double Employee::getSalary()
{
    return this->salary;
}

void Employee::setSalary(double salary)
{
    this->salary = salary;
}

void Employee::acceptData()
{
    Person::acceptData();
    cout << "Enter Employee ID: " << empid;
    cin >> empid;
    cout << "Enter Salary: ";
    cin >> salary;
}

void Employee::displayData()
{
    Person::displayData();
    cout << "Employee ID: " << empid << endl;
    cout << "Salary: " << salary << endl;
}
