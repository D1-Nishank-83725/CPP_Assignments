#include "person.h"

class Student : public Person
{
private:
    int rollno;
    double marks;

public:
    void acceptData();
    void displayData();
};
