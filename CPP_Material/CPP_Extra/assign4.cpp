#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date() : Date(1, 1, 2000) {}

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

    void setDay(int day)
    {
        this->day = day;
    }

    int getMonth()
    {
        return this->month;
    }

    void setMonth(int month)
    {
        this->month = month;
    }

    int getYear()
    {
        return this->year;
    }

    void setYear(int year)
    {
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
        salary = 0.0;
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

    // Main Concept to see

    void getJoiningDate()
    {
        joiningDate.displayDate();
    }

    void setJoiningDate()
    {
        joiningDate.acceptDate();
    }

    void acceptEmployee()
    {
        cout << "Enter the Employee ID: ";
        cin >> id;
        cin >> salary;
        cin >> department;
        joiningDate.acceptDate();
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

    // Main concept to see

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

    return 0;
}
