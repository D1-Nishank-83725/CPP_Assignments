#include <iostream>
#include <vector>
using namespace std;

class Person
{
private:
    string name;

public:
    virtual void acceptData()
    {
        cout << "Enter name - ";
        cin >> name;
    }
    virtual void displayData()
    {
        cout << "Name - " << name << endl;
    }
};

class Student : public Person
{
private:
    int rollno;
    double marks;

public:
    void acceptData()
    {
        cout << "Enter rollno - ";
        cin >> rollno;

        Person::acceptData();

        cout << "Enter marks - ";
        cin >> marks;
    }
    void displayData()
    {
        cout << "Rollno - " << rollno << endl;
        Person::displayData();
        cout << "Marks - " << marks << endl;
    }
};

class Employee : public Person
{
private:
    int empid;
    double salary;

public:
    void acceptData()
    {
        cout << "Enter empid - ";
        cin >> empid;

        Person::acceptData();

        cout << "Enter Salary - ";
        cin >> salary;
    }

    void displayData()
    {
        cout << "Empid - " << empid << endl;

        Person::displayData();

        cout << "Salary - " << salary << endl;
    }
};

int menu()
{
    int choice;
    cout << "\n\n0. EXIT" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Add Student" << endl;
    cout << "3. Display Employees" << endl;
    cout << "4. Display Students" << endl;
    cout << "5. Display All Persons\n\n"
         << endl;
    cout << "Enter your choice - ";
    cin >> choice;
    cout << endl;

    return choice;
}

int main()
{
    int choice;
    vector<Person *> personList;
    Person *ptr;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:

            ptr = new Employee();
            ptr->acceptData();
            personList.push_back(ptr);
            break;

        case 2:

            ptr = new Student();
            ptr->acceptData();
            personList.push_back(ptr);
            break;

        case 3:

            for (int i = 0; i < personList.size(); i++)
            {
                if (typeid(*personList[i]) == typeid(Employee))
                {
                    cout << "Details for Employee at position: " << i + 1 << endl;
                    personList[i]->displayData();
                    cout << endl;
                }
            }
            break;

        case 4:

            for (int i = 0; i < personList.size(); i++)
            {
                if (typeid(*personList[i]) == typeid(Student))
                {
                    cout << "Details for Student at position : " << i + 1 << endl;
                    personList[i]->displayData();
                    cout << endl;
                }
            }
            break;

        case 5:

            for (int i = 0; i < personList.size(); i++)
            {
                personList[i]->displayData();
                cout << endl;
            }
            break;

        default:

            cout << "Wrong choice ..." << endl;
            break;
        }
    }

    for (int i = 0; i < personList.size(); i++)
    {
        delete personList[i];
    }

    cout << "Thank you ... " << endl;
    return 0;
}