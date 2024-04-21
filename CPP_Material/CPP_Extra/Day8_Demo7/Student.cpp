#include "Person.h"
#include "Student.h"


int Student::getRollno()
{
    return this->rollno;
}

void Student::setRollno(int rollno)
{
    this->rollno = rollno;
}

int Student::getMarks()
{
    return this->marks;
}

void Student::setMarks(int marks)
{
    this->marks = marks;
}

void Student::acceptData()
{
    Person::acceptData();
    cout << "Enter Roll Number: ";
    cin >> rollno;
    cout << "Enter Marks: ";
    cin >> marks;
}

void Student::displayData()
{
    Person::displayData();
    cout << "Roll Number: " << rollno << endl;
    cout << "Marks: " << marks << endl;
}

