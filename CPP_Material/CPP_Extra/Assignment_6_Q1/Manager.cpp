// #include "EmployeeException.h"
// #include "Employee.h"
#include <iostream>
using namespace std;
#include "Manager.h"

Manager::Manager() : Manager(0, 0.0f, 0.0) {}

Manager::Manager(int id, float salary, float bonus)
{
    this->id = id;
    this->salary = salary;
    this->bonus = bonus;
}

void Manager::displayBonus()
{
    cout << "Bonus    : " << bonus << endl;
}

void Manager::acceptBonus()
{
    cout << "Enter Bonus: ";
    cin >> bonus;
}

void Manager::acceptData()
{
    Employee::acceptData();
    acceptBonus();
}

void Manager::displayData()
{
    Employee::displayData();
    displayBonus();
}

