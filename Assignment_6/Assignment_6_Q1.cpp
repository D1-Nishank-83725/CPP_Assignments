#include <iostream>
using namespace std;

// Make Individual Objects and check
// Employee Pointer : Class rest wali
// Can you have those functionalites using the

class EmployeeException
{

private:
    string message;

public:
    EmployeeException()
    {
        cout << "Something went wrong " << endl;
    }
    EmployeeException(string message)
    {
        this->message = message;
    }

    void printErrorMessage()
    {
        cout << message << endl;
    }
};

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
        if (salary < 0)
        {
            throw EmployeeException("Salary cannot be less than 0");
        }
    }

    virtual void displayData()
    {
        cout << "ID              : " << id << endl;
        cout << "Salary          : " << salary << endl;
    }

    // Important Step: Because as we try to delete the manager or salesperson class
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
        cout << "Bonus    : " << bonus << endl;
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
        displayComm();
    }
};

class Salesmanager : public Manager, Salesman
{
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
        Manager::acceptBonus();
        Salesman::acceptComm();

        // Salesman::acceptData();
        // Manager::acceptData();
    }

    void displayData()
    {
        Employee::displayData();
        cout << "Bonus        : " << bonus << endl;
        cout << "Commission   : " << comm << endl;
        // Salesman::displayData();
        // Manager::displayData();
    }
};

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
