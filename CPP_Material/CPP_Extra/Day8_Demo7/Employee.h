#include "Person.h"

class Employee : public Person
{
private:
    int empid;
    double salary;

public:
    int getEmpid();
    void setEmpid(int empid);
    double getSalary();
    void setSalary(double salary);
    void acceptData();
    void displayData();
};
