#include <iostream>
using namespace std;

class Student
{
private:
    string student_Name;
    int student_Rollno;
    int student_Marks;

public:
    void initStudent()
    {
        student_Name = "Robert Pattinson";
        student_Rollno = 1;
        student_Marks = 100;
    }

    void printStudentOnConsole()
    {
        cout << "Name        : " << student_Name << endl;
        cout << "Roll Number : " << student_Rollno << endl;
        cout << "Marks       : " << student_Marks << endl;
    }

    void acceptStudentFromConsole()
    {
        printf("Enter the Name\n");
        cin >> student_Name;
        printf("Enter the Roll Number\n");
        cin >> student_Rollno;
        printf("Enter the Marks\n");
        cin >> student_Marks;
    }
};

int main()
{
    Student s1;
    s1.initStudent();
    int choice;

    cout << "Program to Initialize, accept and print Student Details" << endl;

    do
    {
        cout << "\n0: EXIT\n";
        cout << "1: Initialize Student Details to Default (i.e. Name = Robert Pattinson, Roll Number = 1; Marks = 100;)\n";
        cout << "2: Accept Student Details\n";
        cout << "3: Print Student Details\n\n";

        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            s1.initStudent();
            break;
        case 2:
            s1.acceptStudentFromConsole();
            break;
        case 3:
            s1.printStudentOnConsole();
            break;

        default:
            cout << "Invalid Choice!" << endl;
            break;
        }

    } while (choice != 0);

    cout << "\nThank you for using the Program" << endl;

    return 0;
}
