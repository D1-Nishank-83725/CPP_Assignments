#include "EmployeeException.h"
#include "Salesmanager.h"

int main()
{
    int choice;
    int size;
    int count = 0;
    // Employee e1;
    // Manager m1;
    // Salesman sm1;
    // Salesmanager sM1;

    // sM1.acceptData();
    // sM1.displayData();

    cout << "Enter the number of Employees you want to enter: " << endl;
    cin >> size;

    Employee *employees[size];

    do
    {

        cout << "\n\n0: Exit                 : " << endl;
        cout << "1: Accept Employee      : " << endl;
        cout << "2: Display Employee     : " << endl;
        cout << "3: Accept Manager       : " << endl;
        cout << "4: Display Manager      : " << endl;
        cout << "5: Accept Salesman      : " << endl;
        cout << "6: Display Salesman     : " << endl;
        cout << "7: Accept Salesmanager  : " << endl;
        cout << "8: Display Salesmanager : " << endl;
        cout << "9: Display All Data     : \n\n"
             << endl;

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Thank you for using the Program " << endl;
            break;

        case 1:

            if (count < size)
            {
                employees[count] = new Employee();
                try
                {
                    employees[count]->acceptData();
                    count++;
                }
                catch (EmployeeException &error)
                {
                    error.printErrorMessage();
                }
            }
            else
            {
                cout << "Cannot take more Employees" << endl;
            }
            break;

        case 2:
            for (int i = 0; i < count; i++)
            {
                if (typeid(*employees[i]) == typeid(Employee))
                {
                    employees[i]->displayData();
                }
            }
            cout << endl;
            break;

        case 3:
            if (count < size)
            {
                employees[count] = new Manager();
                employees[count]->acceptData();
                count++;
            }
            else
            {
                cout << "Cannot take more Managers" << endl;
            }
            break;

        case 4:
            for (int i = 0; i < count; i++)
            {
                if (typeid(*employees[i]) == typeid(Manager))
                {
                    employees[i]->displayData();
                }
            }
            cout << endl;
            break;

        case 5:
            if (count < size)
            {
                employees[count] = new Salesman();
                employees[count]->acceptData();
                count++;
            }
            else
            {
                cout << "Cannot take more Salesmen" << endl;
            }
            break;

        case 6:
            for (int i = 0; i < count; i++)
            {
                if (typeid(*employees[i]) == typeid(Salesman))
                {
                    employees[i]->displayData();
                    cout << endl;
                }
            }
            cout << endl;
            break;

        case 7:
            if (count < size)
            {
                employees[count] = new Salesmanager();
                employees[count]->acceptData();
                count++;
            }
            else
            {
                cout << "Cannot take more Salesmanger~" << endl;
            }
            break;

        case 8:
            for (int i = 0; i < count; i++)
            {
                if (typeid(*employees[i]) == typeid(Salesmanager))
                {
                    employees[i]->displayData();
                }
            }
            cout << endl;
            break;

        case 9:
            for (int i = 0; i < count; i++)
            {
                employees[i]->displayData();
            }
            break;

        default:
            cout << "Invalid Choice!" << endl;
            break;
        }
    } while (choice != 0);

    for (int i = 0; i < count; i++)
    {
        // free(employees[i]);
        delete employees[i];
    }

    return 0;
}
