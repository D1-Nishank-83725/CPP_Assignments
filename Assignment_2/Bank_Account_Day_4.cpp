#include <iostream>
using namespace std;
class BankAccount
{
private:
    const int accno;
    string name;
    double balance;
    static int generate_accno;

public:
    // accno is constant therefore it was initialized in Constructor member Initializer List
    BankAccount() : accno(++generate_accno) {}

    BankAccount(string name, double balance) : accno(++generate_accno)
    {
        this->name = name;
        this->balance = balance;
    }

    void acceptaccountDeatils()
    {
        cout << "Enter name - ";
        cin >> name;
        cout << "Enter initial Balance - ";
        cin >> balance;
    }

    void displayAccountDeatils()
    {
        cout << "Accno = " << accno << endl;
        cout << "Name = " << name << endl;
        cout << "Balanace = " << balance << endl;
    }
};

int BankAccount::generate_accno = 1000;

int main()
{
    // todo -> do it in menu driven code
    BankAccount *accptr;

    int choice;

    accptr = new BankAccount;
    do
    {
        cout << "\n0: EXIT" << endl;
        cout << "1: Accept Account Details" << endl;
        cout << "2: Display Account Details\n"
             << endl;

        cin >> choice;

        switch (choice)
        {
        case 0:
            delete accptr;
            accptr = NULL;
            break;

        case 1:
            accptr->acceptaccountDeatils();
            break;

        case 2:
            accptr->displayAccountDeatils();
            break;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}

// int main1()
// {
//     BankAccount acc1("rohan", 10000);
//     BankAccount acc2("nilesh", 15000);
//     BankAccount acc3("nitin", 20000);
//     BankAccount acc4("Rajiv", 20000);
//     BankAccount acc5("yogesh", 20000);

//     acc1.displayAccountDeatils();
//     acc2.displayAccountDeatils();
//     acc3.displayAccountDeatils();
//     acc4.displayAccountDeatils();
//     acc5.displayAccountDeatils();

//     return 0;
// }