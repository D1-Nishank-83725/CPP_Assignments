#include <iostream>
#include <vector>
#include "Person.h"
#include "Student.h"
#include "Employee.h"

using namespace std;

int main()
{
    vector<Person *> personList;
    Person *ptr;
    int choice;

    do
    {
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

        switch (choice)
        {
        case 0:
            cout << "Thank you for using the Program" << endl;
            break;

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
                    personList[i]->displayData();
                }
            }

            break;

        case 4:
            for (int i = 0; i < personList.size(); i++)
            {
                if (typeid(*personList[i]) == typeid(Student))
                {
                    personList[i]->displayData();
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
            cout << "Invalid Choice!" << endl;
            break;
        }

    } while (choice != 0);

    for (int i = 0; i < personList.size(); i++)
    {
        delete personList[i];
    }

    return 0;
}
