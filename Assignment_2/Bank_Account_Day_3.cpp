#include <iostream>
using namespace std;

class BankAccount
{
private:
    const int accno;
    string name;
    double balance;

public:
    int amount;
    // Here, we initialized accno in Constructor member initializer list because only CMIL allows for constant data members to be defined, inside constructor we cannot do that

    BankAccount(int accno, string name, double balance) : accno(accno)
    {
        this->name = name;
        this->balance = balance;
    }

    // All Inspectors/Getters can be set to constant

    double getBalance() const
    {
        return balance;
    }

    // can i make the deposit function const? : NO
    void deposit()
    {
        cout << "\nEnter the amount you want to Deposit: " << endl;
        cin >> amount;
        balance += amount;
        cout << "Rupees: " << amount << " Deposited Successfully\n"
             << endl;
    }

    // can i make the deposit function const? : NO
    void withdraw()
    {
        cout << "\nEnter the amount you want to Withdraw: " << endl;
        cin >> amount;
        this->balance -= amount;
        cout << "Rupees: " << amount << " Withdrawn Successfully\n"
             << endl;
    }

    void displayAccountDetails() const
    {
        cout << "Accno - " << accno << endl;
        cout << "Name - " << name << endl;
        cout << "Balance - " << balance << endl;
    }
};

int main()
{
    BankAccount acc1(1001, "rohan", 10000);

    int choice;

    do
    {
        cout << "\n0. EXIT" << endl;
        cout << "1. Display Account details: " << endl;
        cout << "2. Deposit Amount: " << endl;
        cout << "3. Widthdraw Amount: \n"
             << endl;

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Thank you for using the Program \n"
                 << endl;
            break;

        case 1:
            acc1.displayAccountDetails();
            break;

        case 2:
            acc1.deposit();
            break;

        case 3:
            acc1.withdraw();
            break;

        default:
            break;
        }

    } while (choice != 0);

    return 0;
}