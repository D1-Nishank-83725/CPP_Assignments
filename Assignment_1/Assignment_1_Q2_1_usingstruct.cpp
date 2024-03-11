#include <iostream>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

void initDate(Date *ptrDate)
{
    // Here, I have taken a Default date as 1/1/2000, for the purpose of initialization
    ptrDate->day = 1;
    ptrDate->month = 1;
    ptrDate->year = 2000;
}

void printDateOnConsole(Date *ptrDate)
{
    cout << "\nDate: " << ptrDate->day << "-" << ptrDate->month << "-" << ptrDate->year << endl;
}

void acceptDateFromConsole(Date *ptrDate)
{
    cout << "\nEnter the Date: " << endl;
    cin >> ptrDate->day >> ptrDate->month >> ptrDate->year;
}

bool isLeapYear(Date *ptrDate)
{
    if ((ptrDate->year % 4 == 0 && ptrDate->year % 100 != 0) || (ptrDate->year % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Date d1;
    initDate(&d1);
    int choice;

    cout << "Program to Initialize, Accept, Print Date and check if Year is a LEAP YEAR\n";

    do
    {
        cout << "\n0: EXIT\n";
        cout << "1: Initialize Date to Default(1-1-2000)\n";
        cout << "2: Accept Date\n";
        cout << "3: Print Date\n";
        cout << "4: Check if Year is LEAP YEAR\n\n";

        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            initDate(&d1);
            break;
        case 2:
            acceptDateFromConsole(&d1);
            break;
        case 3:
            printDateOnConsole(&d1);
            break;
        case 4:
            if (isLeapYear(&d1))
            {
                cout << d1.year << " is a LEAP YEAR" << endl;
            }
            else
            {
                cout << d1.year << " is NOT a LEAP YEAR" << endl;
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
