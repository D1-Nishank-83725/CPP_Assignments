#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 1;
        month = 1;
        year = 2000;
    }

    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    int getDay()
    {
        return this->day;
    }

    int getMonth()
    {
        return this->month;
    }

    int getYear()
    {
        return this->year;
    }

    void setDay(int day)
    {
        cout << "Enter the Day: ";
        cin >> day;
        this->day = day;
    }

    void setMonth(int month)
    {
        cout << "Enter the Month: ";
        cin >> month;
        this->month = month;
    }

    void setYear(int year)
    {
        cout << "Enter the Year: ";
        cin >> year;
        this->year = year;
    }

    void displayDate()
    {
        cout << "Date: " << day << "/" << month << "/" << year;
    }

    void acceptDate()
    {

        cout << "Enter the Day: ";
        cin >> day;
        this->day = day;

        cout << "Enter the Month: ";
        cin >> month;
        this->month = month;

        cout << "Enter the Year: ";
        cin >> year;
        this->year = year;
    }

    bool isLeapYear()
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            cout << "The given year is a LEAP Year" << endl;
            return true;
        }
        else
        {
            cout << "NOT a LEAP YEAR" << endl;
            return false;
        }
    }
};

class Employee
{
private:
    int id;
    double salary;
    string department;
    Date joiningDate;

public:
    Employee()
    {
        id = 1;
        salary = 10000;
        department = "Sunbeam";
        joiningDate = Date();
    }

    Employee(int id, double salary, string department, Date joiningDate)
    {
        this->id = id;
        this->salary = salary;
        this->department = department;
        this->joiningDate = joiningDate;
    }

    int getId()
    {
        return id;
    }

    double getSalary()
    {
        return salary;
    }

    string getDepartment()
    {
        return department;
    }

    void setId(int id)
    {
        this->id = id;
    }

    void setSalary(int salary)
    {
        this->salary = salary;
    }

    void setDepartment(string department)
    {
        this->department = department;
    }

    // Most important part of Association to understand the concept

    void getJoiningDate()
    {
        joiningDate.displayDate();
    }

    void setJoiningDate()
    {
        joiningDate.acceptDate();
    }

    void displayEmployee()
    {
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
        cout << "Department: " << department << endl;
        cout << "Date of Joining: ";
        joiningDate.displayDate();
        cout << endl;
    }

    void acceptEmployee()
    {
        cout << "Enter ID: " << endl;
        cin >> id;

        cout << "Enter Salary: " << endl;
        cin >> salary;

        cout << "Enter Department: " << endl;
        cin >> department;

        cout << "Enter Date of Joining: " << endl;
        joiningDate.acceptDate();
    }
};

class Person
{
private:
    string name;
    string address;
    Date joiningDate;

public:
    Person()
    {
        name = "John";
        address = "TCG, Pune";
        joiningDate = Date();
    }

    Person(string name, string address, Date joiningdate)
    {
        this->name = name;
        this->address = address;
        this->joiningDate = joiningDate;
    }

    string getName()
    {
        return name;
    }

    string getAddress()
    {
        return address;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setAddress(string address)
    {
        this->address = address;
    }

    // Most important part of Association to understand the concept

    void getBirthDate()
    {
        joiningDate.displayDate();
    }

    void setBirthDate()
    {
        joiningDate.acceptDate();
    }

    void displayPerson()
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birth Date: ";
        joiningDate.displayDate();
        cout << endl;
    }

    void acceptPerson()
    {
        cin.ignore();
        cout << "Enter Name: " << endl;
        getline(cin, name);

        cout << "Enter Address: " << endl;
        getline(cin, address);

        cout << "Enter Birth Date: " << endl;
        joiningDate.acceptDate();
    }
};

int main()
{

    Employee e1;
    Person p1;
    Date d1;

    int choice;

    do
    {

        cout << "\n\n0: EXIT: " << endl;
        cout << "1: Accept Date: " << endl;
        cout << "2: Display Date: " << endl;
        cout << "3: Accept Employee: " << endl;
        cout << "4: Display Employee: " << endl;
        cout << "5: Accept Person: " << endl;
        cout << "6: Display Person \n\n"
             << endl;

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Thank you for using the Program " << endl;
            break;

        case 1:
            d1.acceptDate();
            break;

        case 2:
            d1.displayDate();
            break;

        case 3:
            e1.acceptEmployee();
            break;

        case 4:
            e1.displayEmployee();
            break;

        case 5:
            p1.acceptPerson();
            break;

        case 6:
            p1.displayPerson();
            break;

        default:
            break;
        }

    } while (choice != 0);

    return 0;
}
