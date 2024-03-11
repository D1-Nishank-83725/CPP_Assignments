// Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a fifty-cent toll.
// Mostly they do, but sometimes a car goes by without paying.
// The tollbooth keeps track of the number of cars that have gone by and of the total amount of money
// collected. Model this tollbooth with a class called tollbooth.
// The two data items are a type unsigned int to hold the total number of cars, and a type double to
// hold the total amount of money collected.
// A constructor initializes all data members to 0. A member function called payingCar() increments
// the car total and adds 0.50 to the cash total. An other function, called nopayCar()
// increments the car total but adds nothing to the cash total. Finally, a member function called
// printOnConsole() displays the two totals and number of paying as well as non paying cars total.





#include <iostream>
using namespace std;

class Tollbooth
{
private:
    unsigned int paying_cars;
    unsigned int non_paying_cars;
    double money_collected;

public:
    int payingCarCount = 0;
    int nonPayingCarCount = 0;
    Tollbooth()
    {
        paying_cars = 0;
        non_paying_cars = 0;
        money_collected = 0;
    }

    void payingCar()
    {
        paying_cars += 1;
        payingCarCount += 1;
        cout<< "Total " <<payingCarCount << " paying cars are added"<<endl;
        money_collected += 0.5;
    }

    void noPayCar()
    {
        non_paying_cars += 1;
        nonPayingCarCount += 1;

        cout<< "Total " <<nonPayingCarCount << " non-paying cars are added"<<endl;
    }

    void collectedCash()
    {
        cout << "\nCollected Cash: " << money_collected << endl;
    }

    void totalNoOfCars()
    {
        cout << "\nNumber of Paying Cars:      " << paying_cars << "\nNumber of Non Paying Cars:  " << non_paying_cars << "\nTotal Cars:                 " << paying_cars + non_paying_cars << endl;
    }
};

int main()
{

    Tollbooth t1;
    int choice;

    do
    {
        cout << "\n0: EXIT" << endl;
        cout << "1: Insert a Paying Car" << endl;
        cout << "2: Insert a Non-Paying Car" << endl;
        cout << "3: Display Cash Collected" << endl;
        cout << "4: Display number of Paying and Non-Paying Cars\n"
             << endl;
        
        cout<<endl;
        cout<<"Enter your Choice: ";

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "\nThank you for using the Program" << endl;
            break;

        case 1:
            t1.payingCar();
            break;

        case 2:
            t1.noPayCar();
            break;

        case 3:
            t1.collectedCash();
            break;

        case 4:
            t1.totalNoOfCars();
            break;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}
