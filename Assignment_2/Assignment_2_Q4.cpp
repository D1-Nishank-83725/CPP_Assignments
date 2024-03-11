#include <iostream>
using namespace std;

class Address
{

private:
    string building;
    string street;
    string city;
    int pin;

public:
    // Parameterless Constructor

    Address() : Address("Sunbeam Institute", "Hinjewadi Phase 2 Street", "Pune", 411057) {}

    // Parameterized Constructor

    Address(string building, string street, string city, int pin)
    {
        this->building = building;
        this->street = street;
        this->city = city;
        this->pin = pin;
    }

    void acceptAddress()
    {

        cout << "Set Address: \n"
             << endl;
        cout << "Enter Building: ";
        cin.ignore();
        getline(cin, building);
        cout << "Enter Street: ";
        getline(cin, street);
        cout << "Enter City: ";
        getline(cin, city);
        cout << "Enter Pincode: ";
        cin >> pin;
    }

    void displayAddress()
    {
        cout << "The Address is : " << this->building << ", " << this->street << ", " << this->city << ", " << this->pin << endl
             << endl;
    }

    void setBuilding(string name)
    {
        cout << "Enter Building Name: " << endl;
        cin.ignore();
        getline(cin, name);
        building = name;
    }

    void setStreet(string name)
    {
        cout << "Enter Street Name: " << endl;
        cin.ignore();
        getline(cin, name);
        street = name;
    }

    void setCity(string name)
    {
        cout << "Enter City Name: " << endl;
        cin.ignore();
        getline(cin, name);
        city = name;
    }

    void setPin(int pincode)
    {
        cout << "Enter Pincode: " << endl;
        cin >> pincode;
        pin = pincode;
    }

    string getBuilding()
    {
        return this->building;
    }

    string getStreet()
    {
        return this->street;
    }

    string getCity()
    {
        return this->city;
    }

    int getPin()
    {
        return this->pin;
    }
};

int main()
{

    Address a1;
    cout << "\nPortal for Address (Includes Building, Street, City, Pin)\n"
         << endl;
    int choice;
    string name;
    int pincode;

    do
    {

        cout << "\n0: Exit" << endl;
        cout << "1: Print Address" << endl;
        cout << "2: Set Address" << endl;
        cout << "3: Set Building" << endl;
        cout << "4: Set Street" << endl;
        cout << "5: Set City" << endl;
        cout << "6: Set Pin" << endl;
        cout << "7: Get Address" << endl;
        cout << "8: Get Building" << endl;
        cout << "9: Get Street" << endl;
        cout << "10: Get City" << endl;
        cout << "11: Get Pin\n"
             << endl;

        cout << endl;
        cout << "Enter your Choice: ";

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Thank you for using the Program" << endl;
            break;

        case 1:
            a1.displayAddress();
            break;

        case 2:
            a1.acceptAddress();
            break;

        case 3:
            a1.setBuilding(name);
            break;

        case 4:
            a1.setStreet(name);
            break;

        case 5:
            a1.setCity(name);
            break;

        case 6:
            a1.setPin(pincode);
            break;

        case 7:
            a1.displayAddress();
            break;

        case 8:
            cout << "Building Name: " << a1.getBuilding();
            break;

        case 9:
            cout << "Street Name: " << a1.getStreet();
            break;

        case 10:
            cout << "City Name: " << a1.getCity();
            break;

        case 11:
            cout << "Pincode: " << a1.getPin();
            break;

        default:
            break;
        }

    } while (choice != 0);

    return 0;
}
