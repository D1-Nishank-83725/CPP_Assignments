
// #include "EmployeeException.h"
// #include "Employee.h"
// #include "Manager.h"
#ifndef SALESMANAGER_H
#define SALESMANAGER_H

#include "Salesman.h"

class Salesmanager : public Manager, Salesman
{
public:
    Salesmanager() {}

    Salesmanager(int id, float salary, float bonus, int comm){};
    void acceptData(){};

    void displayData(){};
};

#endif
