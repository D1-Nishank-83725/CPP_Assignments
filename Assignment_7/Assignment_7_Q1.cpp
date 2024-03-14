#include <iostream>
using namespace std;

// Make Individual Objects and check
// Employee Pointer : Class rest wali
// Can you have those functionalites using the

class Employee
{
protected:
    int id;
    float salary;

public:
    Employee() : Employee(0, 0.0f) {}

    Employee(int id, float salary)
    {
        this->id = id;
        this->salary = salary;
    }

    int getId()
    {
        return id;
    }

    float getSalary()
    {
        return salary;
    }

    void setId(int id)
    {
        this->id = id;
    }

    void setSalary(float salary)
    {
        this->salary = salary;
    }

    virtual void acceptData()
    {
        cout << "Enter ID    : ";
        cin >> id;

        cout << "Enter Salary: ";
        cin >> salary;
    }

    virtual void displayData()
    {
        cout << "ID               : " << id << endl;
        cout << "Salary           : " << salary << endl;
    }

    virtual ~Employee()
    {
    }
};

class Manager : virtual public Employee
{
protected:
    int bonus;

public:
    Manager() : Manager(0, 0.0f, 0.0) {}

    Manager(int id, float salary, float bonus)
    {
        this->id = id;
        this->salary = salary;
        this->bonus = bonus;
    }

    void displayBonus()
    {
        cout << "Bonus        : " << bonus << endl;
    }

    void acceptBonus()
    {
        cout << "Enter Bonus: ";
        cin >> bonus;
    }

    void acceptData()
    {
        Employee::acceptData();
        acceptBonus();
    }

    void displayData()
    {
        Employee::displayData();
        displayBonus();
    }
};

class Salesman : virtual public Employee
{
protected:
    int comm;

public:
    Salesman() : Salesman(0, 0.0f, 0) {}

    Salesman(int id, float salary, int comm)
    {
        this->id = id;
        this->salary = salary;
        this->comm = comm;
    }

    void displayComm()
    {
        cout << "Commission       : " << comm << endl;
    }

    void acceptComm()
    {
        cout << "Enter Commission : ";
        cin >> comm;
    }

    void acceptData()
    {
        Employee::acceptData();
        acceptComm();
    }

    void displayData()
    {
        Employee::displayData();
        cout << "Commission             : " << comm << endl;
        ;
    }
};

class Salesmanager : public Manager, public Salesman
{
protected:
public:
    Salesmanager() : Salesmanager(0, 0.0f, 0.0f, 0.0) {}

    Salesmanager(int id, float salary, float bonus, int comm)
    {
        this->id = id;
        this->salary = salary;
        this->bonus = bonus;
        this->comm = comm;
    }
    void acceptData()
    {
        Employee::acceptData();
        acceptBonus();
        acceptComm();
        // Salesman::acceptData();
        // Manager::acceptData();
    }

    void displayData()
    {
        Employee::displayData();
        displayBonus();
        displayComm();
        // Salesman::displayData();
        // Manager::displayData();
    }
};

int menu()
{
    int choice;
    cout << "\n\n0: Exit                   : " << endl;
    cout << "1: Accept Employee        : " << endl;
    cout << "2: Display Employee       : " << endl;
    cout << "3: Accept Manager         : " << endl;
    cout << "4: Display Manager        : " << endl;
    cout << "5: Accept Salesman        : " << endl;
    cout << "6: Display Salesman       : " << endl;
    cout << "7: Accept Salesmanager    : " << endl;
    cout << "8: Display Salesmanager   : " << endl;
    cout << "9: Count Of All Employees : " << endl;
    cout << "10: Display All Data      : \n\n"
         << endl;

    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    int size;
    int count = 0;

    int noOfEmployees = 0;
    int noOfManagers = 0;
    int noOfSalesman = 0;
    int noOfSalesmanagers = 0;
    // Employee e1;
    // Manager m1;
    // Salesman sm1;
    // Salesmanager sM1;

    // sM1.acceptData();
    // sM1.displayData();

    cout << "Enter the number of Employees you want to enter: " << endl;
    cin >> size;

    Employee *employees[size];

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            if (count < size)
            {
                employees[count] = new Employee();
                employees[count]->acceptData();
                noOfEmployees++;
                count++;
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
                noOfManagers++;
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
                noOfSalesman++;
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
                noOfSalesmanagers++;
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
        {
            cout << "Employees     : " << noOfEmployees << endl;
            cout << "Managers      : " << noOfManagers << endl;
            cout << "Salesman      : " << noOfSalesman << endl;
            cout << "Sales Manager : " << noOfSalesmanagers << endl;
        }
        break;

        case 10:
            for (int i = 0; i < count; i++)
            {
                employees[i]->displayData();
            }
            break;

        default:
            cout << "Invalid Choice!" << endl;
            break;
        }
    }

    for (int i = 0; i < count; i++)
    {
        delete[] employees[i];
        employees[i] = NULL;
    }

    cout << "Thank you for using the program" << endl;

    return 0;
}
