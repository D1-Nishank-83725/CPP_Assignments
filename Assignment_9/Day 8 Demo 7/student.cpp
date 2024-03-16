#include "person.h"
#include "student.h"


void Student::acceptData()
{
    cout << "Enter rollno - ";
    cin >> rollno;

    Person::acceptData();

    cout << "Enter marks - ";
    cin >> marks;
}

void Student::displayData()
{
    cout << "Rollno - " << rollno << endl;
    Person::displayData();
    cout << "Marks - " << marks << endl;
}

