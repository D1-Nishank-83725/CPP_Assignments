// #include "EmployeeException.h"
// #include "Employee.h"
#ifndef SALESMAN_H
#define SALESMAN_H

#include "Manager.h"
// #include "Employee.h"

class Salesman : virtual public Employee
{
protected:
    int comm;

public:
    Salesman() : Salesman(0, 0.0f, 0){};

    Salesman(int id, float salary, int comm){};

    void displayComm(){};

    void acceptComm(){};

    void acceptData(){};

    void displayData(){};
};

#endif
