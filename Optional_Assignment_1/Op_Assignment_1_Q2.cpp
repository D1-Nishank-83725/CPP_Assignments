#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    string name;
    double salary;
    static int incrementno;

public:
    Employee() : Employee("", 0.0) {}

    Employee(string name, double salary) : id(++incrementno)
    {
        this->name = name;
        this->salary = salary;
    }

    void acceptEmployee()
    {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Salary: ";
        cin >> salary;
        cout << endl;
    }

    void DisplayEmployee()
    {
        cout << "EmpID : " << id << endl;
        cout << "Name  : " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << endl;
    }

    int getId()
    {
        return id;
    }
};

void printEmpInfoById(Employee *arr[], int id, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (id == arr[i]->getId())
        {
            cout << "Employee found at \"" << i + 1 << "\" position" << endl;
        }
    }
}

int Employee::incrementno = 1000;

int main()
{
    int size, choice, id;
    cout << "\nEnter the number of Employees you want: ";
    cin >> size;

    Employee *arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = new Employee;
    }

    do
    {
        cout << "\n\n0: Exit " << endl;
        cout << "1: Accept Employees " << endl;
        cout << "2: Display Employees " << endl;
        cout << "3: Enter Employee ID to find out Employee Information \n"
             << endl;

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Thank you for using the program " << endl;
            break;

        case 1:
            for (int i = 0; i < size; i++)
            {
                arr[i]->acceptEmployee();
            }
            break;

        case 2:
            for (int i = 0; i < size; i++)
            {
                arr[i]->DisplayEmployee();
            }
            break;

        case 3:
            cout << "Enter the ID to find if Employee exists: ";
            cin >> id;
            printEmpInfoById(arr, id, size);
            break;

        default:
            cout << "Invalid Choice!" << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}