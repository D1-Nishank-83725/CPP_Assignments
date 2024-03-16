#include "person.h"


class Employee : public Person
{
private:
    int empid;
    double salary;

public:
    void acceptData();
    void displayData();
};
