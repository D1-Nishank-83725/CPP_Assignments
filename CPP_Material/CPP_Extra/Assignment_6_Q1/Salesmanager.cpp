#include "EmployeeException.h"
// #include "Employee.h"
// #include "Manager.h"
// #include "Salesman.h"
#include "Salesmanager.h"

Salesmanager::Salesmanager() : Salesmanager(0, 0.0f, 0.0f, 0.0) {}

Salesmanager::Salesmanager(int id, float salary, float bonus, int comm)
{
    this->id = id;
    this->salary = salary;
    this->bonus = bonus;
    this->comm = comm;
}
void Salesmanager::acceptData()
{
    Employee::acceptData();
    Manager::acceptBonus();
    Salesman::acceptComm();

    // Salesman::acceptData();
    // Manager::acceptData();
}

void Salesmanager::displayData()
{
    Employee::displayData();
    cout << "Bonus        : " << bonus << endl;
    cout << "Commission   : " << comm << endl;
    // Salesman::displayData();
    // Manager::displayData();
}
