#ifndef EMPLOYEE_H
#define EMPLOYEE_H

// #include "EmployeeException.h"

class Employee
{
protected:
    int id;
    float salary;

public:
    Employee(){}

    Employee(int id, float salary) {}

    int getId();

    float getSalary();
    
    void setId(int id);
    

    void setSalary(float salary);

    virtual void acceptData();

    virtual void displayData();

    // Important Step: Because as we try to delete the manager or salesperson class
    virtual ~Employee();
    
};

#endif
