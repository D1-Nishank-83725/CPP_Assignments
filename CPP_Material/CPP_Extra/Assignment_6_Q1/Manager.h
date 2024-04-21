// #include "EmployeeException.h"
#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : virtual public Employee
{
protected:
    int bonus;

public:
    Manager(){}

    Manager(int id, float salary, float bonus){}

    void displayBonus(){}

    void acceptBonus(){}

    void acceptData(){}

    void displayData(){}
};

#endif
