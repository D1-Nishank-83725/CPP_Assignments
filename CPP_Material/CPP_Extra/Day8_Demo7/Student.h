#include "Person.h"

class Student : public Person
{
private:
    int rollno;
    int marks;

public:

    int getRollno();
    void setRollno(int rollno);
    int getMarks();
    void setMarks(int marks);
    void acceptData();
    void displayData();
    
};

