#include <iostream>
using namespace std;

class Date
{

private:
    int day;
    int month;
    int year;

public:
    void initDate()
    {
        // Here, I have taken a Default date as 1/1/2000, for the purpose of initialization
        day = 1;
        month = 1;
        year = 2000;
    }

    void acceptDateFromConsole()
    {
        cout << "Enter a Date: " << endl;
        cin >> day >> month >> year;
    }

    void printDateOnConsole()
    {
        cout << "Date: " << day << "-" << month << "-" << year << endl;
    }

    bool isLeapYear()
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Date d1;

    int choice;
    d1.initDate();

    cout << "Program to Initialize, Accept, Print Date & check if Year is a Leap Year" << endl;

    do
    {

        cout << "\n0: EXIT\n";
        cout << "1: Initialize Date to Default (i.e. 1/1/2000)\n";
        cout << "2: Accept Date\n";
        cout << "3: Print Date\n";
        cout << "4: Check if Year is LEAP YEAR\n\n";

        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            d1.initDate();
            break;
        case 2:
            d1.acceptDateFromConsole();
            break;
        case 3:
            d1.printDateOnConsole();
            break;
        case 4:
            if (d1.isLeapYear())
            {
                d1.printDateOnConsole();
                cout << "LEAP YEAR" << endl;
            }
            else
            {
                d1.printDateOnConsole();
                cout << "NOT a LEAP YEAR" << endl;
            }
            break;

        default:
            cout << "Invalid Choice!" << endl;
            break;
        }
    } while (choice != 0);
    
    cout << "\nThank you for using the Program" <<endl;

    return 0;
}
