#include <iostream>
using namespace std;

class Product
{

private:
    int id;
    string title;
    double price;

public:
    int totalPrice = 0;
    // Constructors for Initialization

    Product() : Product(0, "", 0.0) {}

    Product(int id, string title, double price)
    {
        this->id = id;
        this->title = title;
        this->price = price;
    }

    virtual void acceptProduct()
    {
        cout << "Enter ID    : ";
        cin >> id;
        this->id = id;

        cout << "Enter Title : ";
        cin.ignore();
        getline(cin, title);
        this->title = title;

        cout << "Price       : ";
        cin >> price;
        this->price = price;
    }

    virtual void displayProduct()
    {
        cout << "Id     : " << id << endl;
        cout << "Title  : " << title << endl;
        cout << "Price  : " << price << endl;
    }

    virtual int getPrice()
    {
        return price;
    }

    // Derived function is partially incomplete therefore, no need for pure virtual function
    // virtual void calcFinalBill() = 0;
    // virtual void displayProduct() = 0;
};

class Book : public Product
{
private:
    string author;

public:
    // Constructors Declared

    Book() : Book("") {}

    Book(string author)
    {
        this->author = author;
    }

    int bookPrice = 0;
    // Book specific member functions

    void acceptProduct()
    {
        Product::acceptProduct();
        cout << "Enter the Author: ";
        cin.ignore();
        getline(cin, author);
    }

    void displayProduct()
    {
        Product::displayProduct();
        cout << "Author: " << author << endl;
    }

    int getPrice()
    {
        return (Product::getPrice() * 0.9);
    }
};

// Remember to-do Inheritance publically
class Tapes : public Product
{
private:
    string artist;

public:
    int tapePrice = 0;

    Tapes() : Tapes("") {}

    Tapes(string artist)
    {
        this->artist = artist;
    }

    void acceptProduct()
    {
        Product::acceptProduct();
        cout << "Enter Artist: ";
        cin.ignore();
        getline(cin, artist);
    }

    void calcFinalBill()
    {
        int tapePrice = 0.9 * getPrice();
        totalPrice += tapePrice;
    }

    void displayProduct()
    {
        Product::displayProduct();
        cout << "Artist : " << artist << endl;
    }

    int getPrice()
    {
        return (Product::getPrice() * 0.95);
    }
};

int menu()
{
    int choice;

    cout << "\n0: Exit " << endl;
    cout << "1: Buy a Book" << endl;
    cout << "2: Buy a Tape" << endl;
    cout << "3: Display Book" << endl;
    cout << "4: Display Tape" << endl;
    cout << "5: Display All Product" << endl;
    cout << "6: Display Final Bill \n\n"
         << endl;

    cin >> choice;

    return choice;
}

int main()
{
    int choice;
    int finalPrice;
    int count = 0;

    Product *productarr[3];

    while ((choice = menu()) != 0)
    {

        switch (choice)
        {
        case 0:
            cout << "Thank you for using the Program " << endl;
            break;

        case 1:
            if (count < 3)
            {
                productarr[count] = new Book();
                productarr[count]->acceptProduct();
                // Book *bptr = (Book *)pptr;
                // bptr->calcFinalBill();
                count++;
            }
            else
            {
                cout << "Cannot add more than 3 products " << endl;
            }
            break;

        case 2:
            if (count < 3)
            {
                productarr[count] = new Tapes();
                productarr[count]->acceptProduct();
                // Tapes *bptr = (Tapes *)pptr;
                // bptr->calcFinalBill();
                count++;
            }
            else
            {
                cout << "Cannot add more than 3 products " << endl;
            }
            break;

        case 3:

            cout << "**************************" << endl;

            for (int i = 0; i < count; i++)
            {
                if (typeid(*productarr[i]) == typeid(Book))
                {
                    productarr[i]->displayProduct();
                }
            }
            cout << "**************************" << endl;
            break;

        case 4:
            cout << "**************************" << endl;
            for (int i = 0; i < count; i++)
            {
                if (typeid(*productarr[i]) == typeid(Tapes))
                {
                    productarr[i]->displayProduct();
                }
            }

            cout << "**************************" << endl;
            break;

        case 5:
            cout << "**************************" << endl;
            for (int i = 0; i < count; i++)
            {
                productarr[i]->displayProduct();
                cout << endl;
            }
            break;

        case 6:
            finalPrice = 0;
            cout << "**************************" << endl;
            for (int i = 0; i < count; i++)
            {
                finalPrice += productarr[i]->getPrice();
            }
            cout << "Final Disounted Price of All Products: " << finalPrice << endl;
            cout << "**************************";
            break;

        default:
        {
            cout << "Invalid Choice! " << endl;
            break;
        }
        }
    }
    for (int i = 0; i < count; i++)
    {
        delete productarr[i];
    }

    return 0;
}
