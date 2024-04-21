#include <iostream>
#include <vector>
using namespace std;

// Class Sports

class Sports
{
private:
    string sports_name;
    double fees;

public:
    // Constructor : Both Parameterless and Parameterized written here, also used Constructor Delegation here
    Sports() : Sports("", 0.0) {}

    Sports(string sports_name, double fees)
    {
        this->sports_name = sports_name;
        this->fees = fees;
    }

    // Getters, Setters

    string getSports_name()
    {
        return sports_name;
    }

    void setSports_name(string sports_name)
    {
        this->sports_name = sports_name;
    }

    double getFees()
    {

        return fees;
    }

    void setFees(double fees)
    {
        this->fees = fees;
    }

    void acceptSport()
    {
        cout << "Enter the Sport's name: ";
        cin >> sports_name;
        cout << "Enter the Fees: ";
        cin >> fees;
    }

    void displaySport()
    {
        cout << "Sport's Name: " << sports_name << endl;
        cout << "Fees: " << fees << endl;
    }
};

// Class Person

class Person
{
private:
    string name;
    int age;

public:
    // Constructor
    Person() : Person("", 0) {}

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    // Getters Setters

    int getAge()
    {
        return age;
    }
    void setAge(int age)
    {
        this->age = age;
    }

    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void accept()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
    }

    void display()
    {
        cout << "\nName: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Class Player publically inherited from Person

class Player : public Person
{

private:
    int id;
    long int mobileNo;
    // Using a Vector to store list of sports a player has enrolled into

    // Sports sportobj;

public:
    vector<Sports> sportsList;
    Player() : Player(0, 0) {}

    Player(int id, long int mobileNo)
    {
        this->id = id;
        this->mobileNo = mobileNo;
    }

    int getId()
    {
        return id;
    }

    void setId(int id)
    {
        this->id = id;
    }

    long getMobileNo()
    {
        return mobileNo;
    }

    void setMobileNo(long int mobileNo)
    {
        this->mobileNo = mobileNo;
    }

    void accept()
    {
        Person::accept();
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Mobile Number: ";
        cin >> mobileNo;
    }

    void display()
    {
        Person::display();
        cout << "ID: " << id << endl;
        cout << "Mobile Number: " << mobileNo << endl;
        for (int i = 0; i < sportsList.size(); i++)
        {
            sportsList[i].displaySport();
        }
    }
};

int main()
{
    int choice, idvalue;
    string sportsnamevalue, namevalue;

    vector<Player> playerList;
    Player p;

    vector<Sports> sportsList;
    Sports s;

    do
    {
        cout << "\n\n0: Exit " << endl;
        cout << "1: Add new Player " << endl;
        cout << "2: Add new Sport " << endl;
        cout << "3: Enroll Player into Sport " << endl;
        cout << "4: Enter Player Name and get Sports List " << endl;
        cout << "5: Display all Players and their Sports Registered \n\n"
             << endl;

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Thank you for using the Program " << endl;
            break;

        case 1:
            p.accept();
            playerList.push_back(p);
            break;

        case 2:
            s.acceptSport();
            sportsList.push_back(s);
            break;

        case 3:
            cout << "Enter your ID to enroll into Sport: ";
            cin >> idvalue;
            for (int i = 0; i < playerList.size(); i++)
            {
                if (playerList[i].getId() == idvalue)
                {
                    cout << "Enter the Sport you want to Enroll to: ";
                    cin >> sportsnamevalue;
                    for (int j = 0; j < sportsList.size(); j++)
                    {

                        if (sportsList[j].getSports_name() == sportsnamevalue)
                        {
                            playerList[i].sportsList.push_back(s);
                            cout << endl;
                            cout << playerList[i].getName() << " successfully Enrolled in " << sportsnamevalue;
                            cout << endl;
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    // cout << "Invalid Sport Entered" << endl;
                    // break;

                }
                else
                {
                    continue;
                }
            }
            // cout << "Invalid ID!" << endl;
            

            break;

        case 4:
            cout << "Enter your Name: ";
            cin >> namevalue;
            for (int i = 0; i < playerList.size(); i++)
            {
                if (playerList[i].getName() == namevalue)
                {
                    // cout << namevalue << "enrolled Sports: ";
                    playerList[i].display();
                    break;
                }
                else
                {
                    cout << "Invalid Name Entered!" << endl;
                }
            }

            break;

        case 5:
            for (int i = 0; i < playerList.size(); i++)
            {
                playerList[i].display();
                cout << endl;
            }

            break;

        default:
            cout << "Invalid Choice!" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
