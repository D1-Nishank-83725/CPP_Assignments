#include <iostream>
using namespace std;

enum Etime
{
    EXIT,
    DISPLAY_TIME,
    DISPLAY_HOURS,
    DISPLAY_MINUTES,
    DISPLAY_SECONDS,
    SET_TIME,
    SET_HOURS,
    SET_MINUTES,
    SET_SECONDS

};

class Time
{

private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() : Time(1, 1, 1) {}

    Time(int hours, int minutes, int seconds)
    {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    void setTime(int hours, int minutes, int seconds)
    {
        cout << "Enter Hours: ";
        cin >> hours;
        this->hours = hours;

        cout << "Enter Minutes: ";
        cin >> minutes;
        this->minutes = minutes;

        cout << "Enter Seconds: ";
        cin >> seconds;
        this->seconds = seconds;
    }

    void setHour(int hours)
    {
        // cout << "Enter Hours: ";
        // cin >> hours;
        this->hours = hours;
    }

    void setMinutes(int minutes)
    {
        // cout << "Enter Minutes: ";
        // cin >> minutes;
        this->minutes = minutes;
    }

    void setSeconds(int seconds)
    {
        // cout << "Enter Seconds: ";
        // cin >> seconds;
        this->seconds = seconds;
    }

    int getHour()
    {
        return hours;
    }

    int getMinute()
    {
        return minutes;
    }

    int getSeconds()
    {
        return seconds;
    }

    void getTime()
    {
        cout << hours << " : " << minutes << " : " << seconds << endl;
    }
};

int main()
{
    // Time arr[5] = { Time(6,30,0), Time(8,0,0), Time(13,30,0), Time(02, 15, 0), Time(6, 0, 0) };
    int noOfObj;
    cout << "Enter the number of Objects you want to create: " << endl;
    cin >> noOfObj;

    Time *arr = new Time[noOfObj];

    int value, choice;

    do
    {
        cout << "0: EXIT " << endl;
        cout << "1: Print Time:  " << endl;
        cout << "2: Get Hours:   " << endl;
        cout << "3: Get Minutes: " << endl;
        cout << "4: Get Seconds: " << endl;
        cout << "5: Set Time:    " << endl;
        cout << "6: Set Hours:   " << endl;
        cout << "7: Set Minutes: " << endl;
        cout << "8: Set Seconds: \n\n"
             << endl;

        cin >> choice;

        switch (choice)
        {
        case EXIT:
            cout << "\nThank you for using the Program" << endl;
            break;

        case DISPLAY_TIME:
            for (int i = 0; i < noOfObj; i++)
            {
                cout << "\nTime for Obj " << i + 1 << ": ";
                arr[i].getTime();
                cout << endl;
            }
            break;

        case DISPLAY_HOURS:
            for (int i = 0; i < noOfObj; i++)
            {
                cout << "\nHour for Obj " << i + 1 << ": ";
                cout << arr[i].getHour();
                cout << endl;
            }
            break;

        case DISPLAY_MINUTES:
            for (int i = 0; i < noOfObj; i++)
            {

                cout << "\nMinute for Obj " << i + 1 << ": ";
                cout << arr[i].getMinute();
                cout << endl;
            }
            break;

        case DISPLAY_SECONDS:
            for (int i = 0; i < noOfObj; i++)
            {
                cout << "\nSeconds for Obj " << i + 1 << ": ";
                cout << arr[i].getSeconds();
                cout << endl;
            }
            break;

        case SET_TIME:
            for (int i = 0; i < noOfObj; i++)
            {
                arr[i].setTime(value, value, value);
                cout << endl;
            }
            break;

        case SET_HOURS:
            for (int i = 0; i < noOfObj; i++)
            {
                cout << "\nEnter Hours for Object " << i + 1 << ": ";
                cin >> value;
                arr[i].setHour(value);
            }
            break;

        case SET_MINUTES:
            for (int i = 0; i < noOfObj; i++)
            {
                cout << "\nEnter Minutes for Object " << i + 1 << ": ";
                cin >> value;
                arr[i].setMinutes(value);
            }
            break;

        case SET_SECONDS:
            for (int i = 0; i < noOfObj; i++)
            {
                cout << "\nEnter Seconds for Object " << i + 1 << ": ";
                cin >> value;
                arr[i].setSeconds(value);
            }
            break;

        default:
            cout << "\nInvalid Choice" << endl;
            break;
        }

    } while (choice != 0);
    delete[] arr;
    return 0;
}