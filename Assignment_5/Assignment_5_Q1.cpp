#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    // Used Constructor Delegation Here

    Date() : Date(1, 1, 1) {}

    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void acceptDate()
    {
        cout << "\nEnter the Day: ";
        cin >> day;
        this->day = day;
        cout << "Enter the Month: ";
        cin >> month;
        this->month = month;
        cout << "Enter the Year: ";
        cin >> year;
        this->year = year;
    }

    void displayDate()
    {
        cout << day << "/" << month << "/" << year;
    }
};

class Person
{

private:
    string name;
    string address;
    // Making an object of Date directly by using Inheritance, instead of implementing the Date functionalities again
    // This is also called as Composition or Tight Binding
    Date birthDate;

public:
    Person() : Person("", "", birthDate) {}

    Person(string name, string address, Date birthdate)
    {
        this->name = name;
        this->address = address;
        this->birthDate = birthDate;
    }

    void acceptPerson()
    {

        cout << "\nEnter the Name: ";
        cin.ignore();
        getline(cin, name);
        this->name = name;

        cout << "Enter the Address: ";
        getline(cin, address);
        this->address = address;

        cout << "Enter the BirthDate: ";
        birthDate.acceptDate();
        this->birthDate = birthDate;
    }

    void displayPerson()
    {
        cout << "\nName: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "BirthDate: ";
        birthDate.displayDate();
    }
};

class Employee : public Person
{
private:
    int empId;
    double salary;
    string department;
    // Making an object of Date directly by using Inheritance, instead of implementing the Date functionalities again
    Date joiningDate;
    // Making an object of Person directly by using Inheritance, instead of implementing the Person functionalities again
    Person p;

public:
    Employee() : Employee(1, 1000.0, "Sunbeam", joiningDate, p) {}

    Employee(int empId, double salary, string department, Date joiningDate, Person p)
    {
        this->empId = empId;
        this->salary = salary;
        this->department = department;
        this->joiningDate = joiningDate;
        this->p = p;
    }

    void acceptEmployee()
    {

        // Here, Inheritance was used
        p.acceptPerson();

        cout << "\nEnter the Employee ID: ";
        cin >> empId;
        this->empId = empId;

        cout << "Enter the Salary: ";
        cin >> salary;
        this->salary = salary;

        cout << "Enter the Department: ";
        cin.ignore();
        getline(cin, department);
        this->department = department;

        cout << "Enter the Joining Date: ";
        joiningDate.acceptDate();
        this->joiningDate = joiningDate;
    }

    void displayEmployee()
    {
        // Here, Inheritance was used
        p.displayPerson();
        cout << "\nEmployee ID: " << empId << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
        cout << "Joining Date: ";
        joiningDate.displayDate();
    }
};

int main()
{
    int size;
    cout << "Enter the Number of Employees you want" << endl;
    cin >> size;
    Employee *emparr[size];

    for (int i = 0; i < size; i++)
    {
        emparr[i] = new Employee;
    }

    Date d1;
    Person p1;
    int choice;

    do
    {
        cout << "\n0: EXIT" << endl;
        cout << "1: Accept Date: " << endl;
        cout << "2: Accept Person: " << endl;
        cout << "3: Accept Employee: " << endl;
        cout << "4: Display Date: " << endl;
        cout << "5: Display Person " << endl;
        cout << "6: Display Employee: \n"
             << endl;

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "\nThank you for using the Program" << endl;
            break;

        case 1:
            d1.acceptDate();
            break;

        case 2:
            p1.acceptPerson();
            break;

        case 3:
            for (int i = 0; i < size; i++)
            {
                cout << "Enter Details for Employee " << i + 1 << endl;
                emparr[i]->acceptEmployee();
                cout << endl;
            }

            break;

        case 4:
            d1.displayDate();
            break;

        case 5:
            p1.displayPerson();
            break;

        case 6:
            for (int i = 0; i < size; i++)
            {
                cout << "\nEmployee " << i + 1 << " Details: " << endl;
                emparr[i]->displayEmployee();
                cout << endl;
            }

            break;

        default:
            cout << "Invalid Choice!" << endl;
            break;
        }

    } while (choice != 0);

    for (int i = 0; i < size; i++)
    {
        delete emparr[i];
    }

    return 0;
}