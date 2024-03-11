
#include <iostream>
using namespace std;
class Box
{

private:
    double length;
    double width;
    double height;

public:
    // Constructor Delegation

    Box() : Box(1) {}

    Box(int value) : Box(1, 1, 1) {}

    // //Parameterized Constructor

    Box(double length, double width, double height)
    {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    // void setVolume()
    // {
    //     length = 1;
    //     width = 1;
    //     height = 1;
    // }

    void printVolume()
    {
        cout << "Volume: " << length * width * height << endl;
    }

    void acceptLengthWidthHeight()
    {
        cout << "Enter Length of Box: " << endl;
        cin >> length;
        cout << "Enter Width of Box: " << endl;
        cin >> width;
        cout << "Enter Height of Box: " << endl;
        cin >> height;
    }
};

int main()
{
    Box b1;
    // double length, width, height;
    int choice;

    do
    {
        cout << "\n0: EXIT" << endl;
        cout << "1: Accept Values for calculating volume" << endl;
        cout << "2: Display Volume\n"
             << endl;
        cout << endl;
        cout << "Enter your Choice: ";

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "\n Thank you for using the Program" << endl;
            break;

        case 1:
            b1.acceptLengthWidthHeight();
            break;

        case 2:
            b1.printVolume();
            break;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}
