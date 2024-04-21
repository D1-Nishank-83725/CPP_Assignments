#include <iostream>
using namespace std;

class ServicingException
{
private:
    string message;

public:
    ServicingException()
    {
        cout << "Something went Wrong " << endl;
    }
    ServicingException(string message)
    {
        this->message = message;
    }

    void printErrorMessage()
    {
        cout << message << endl;
    }
};

class Servicing
{
private:
    string customerName;
    int vehicleNo;
    long int mobileNo;
    double totalBill;

public:
    Servicing() : Servicing("", 0, 0) {}

    Servicing(string customerName, int vehicleNo, long int mobileNo)
    {
        this->customerName = customerName;
        this->vehicleNo = vehicleNo;
        this->mobileNo = mobileNo;
    }

    void enterVehicleNo()
    {
        cout << "Enter Vehicle Number: ";
        cin >> vehicleNo;
    }

    virtual void acceptDetails()
    {
        cout << "Enter Customer Name: ";
        cin >> customerName;
        cout << "Enter Mobile Number: ";
        cin >> mobileNo;
    }

    virtual void displayDetails()
    {
        cout << "Name : " << customerName << endl;
        cout << "Phone No: " << mobileNo << endl;
    }

    // Making Function Virtual: Class becomes Abstract, now have to define it in Derived Class
    virtual void calculateTotalBill() = 0;

    // Getter Function to access totalBill as it will be inaccessible when inherited, becuase it is private
    int getTotalBill()
    {
        return totalBill;
    }

    virtual ~Servicing()
    {
    }
};

// Public Inheritance

class MaintainenceRepairing : public Servicing
{
private:
    string partName;
    double partPrice;
    double labourCharge;
    double maintainenceRepairingTotalBill;

public:
    MaintainenceRepairing() : MaintainenceRepairing("", 0.0, 0.0) {}

    MaintainenceRepairing(string partName, double partPrice, double labourCharge)
    {
        this->partName = partName;
        this->partPrice = partPrice;
        this->labourCharge = labourCharge;
    }

    void acceptDetails()
    {
        Servicing::acceptDetails();
        Servicing::enterVehicleNo();
        cout << "Enter the Vehicle Part to be Replaced: ";
        cin >> partName;
        cout << "Enter the Vehicle Part's Price :";
        cin >> partPrice;
        if (partPrice < 0)
        {
            throw ServicingException("Part's Price cannot be Negative");
        }

        cout << "Enter Labour Charge: ";
        cin >> labourCharge;
        if (labourCharge < 0)
        {
            throw ServicingException("Labour Charge can't be Negative");
        }
    }

    int addGST(int value)
    {
        partPrice = partPrice + ((5 * partPrice) / 100);
        labourCharge = labourCharge + ((5 * labourCharge) / 100);
        return partPrice + labourCharge;
    }

    void calculateTotalBill()
    {
        maintainenceRepairingTotalBill = getTotalBill();
        maintainenceRepairingTotalBill = partPrice + labourCharge;
        cout << "Total Bill to Pay: " << addGST(maintainenceRepairingTotalBill);
    }

    void displayDetails()
    {
        Servicing::displayDetails();
        cout << "Part Name: " << partName << endl;
        cout << "Part Price: " << partPrice << endl;
        cout << "Labour Charge: " << labourCharge << endl;
    }

    ~MaintainenceRepairing()
    {
    }
};

// Public Inheritance

class EngineOilChange : public Servicing
{
private:
    string oilName;
    double oilPrice;
    double engineOilChangeTotalBill;

public:
    EngineOilChange() : EngineOilChange("", 0.0) {}

    EngineOilChange(string oilName, double oilPrice)
    {
        this->oilName = oilName;
        this->oilPrice = oilPrice;
    }

    void acceptDetails()
    {
        Servicing::acceptDetails();
        Servicing::enterVehicleNo();
        cout << "Enter the Oil Brand Name ";
        cin >> oilName;
        cout << "Enter the Oil's Price :";
        cin >> oilPrice;
        if (oilPrice < 0)
        {
            throw ServicingException("Oil Price cannot be Negative");
        }
        }

    int addGST(int oilPrice)
    {
        oilPrice = oilPrice + ((12 * oilPrice) / 100);
        return oilPrice;
    }

    void calculateTotalBill()
    {
        // addGST();
        engineOilChangeTotalBill = getTotalBill();
        engineOilChangeTotalBill = oilPrice;
        cout << "Total Bill to Pay: ";
        cout << addGST(engineOilChangeTotalBill);
    }

    void displayDetails()
    {
        Servicing::displayDetails();
        cout << "Oil Brand Name: " << oilName << endl;
        cout << "Oil Brand Price: " << oilPrice << endl;
    }

    ~EngineOilChange()
    {
    }
};

int main()
{
    // Created objects as no specific instruction was given in the Question
    int count = 0;

    int size;
    cout << "Enter the number of users you want: " << endl;
    cin >> size;

    Servicing *sptr[size];

    int choice;

    do
    {
        // Menu - Driven Code

        cout << "\n\n0: EXIT " << endl;
        cout << "1: Accept Details for Maintainence/Repairing " << endl;
        cout << "2: Display Details for Maintainence/Repairing " << endl;
        cout << "3: Calculate Total Bill for Maintainence/Repairing " << endl;
        cout << "4: Accept Details for Engine/Gear Oil Change " << endl;
        cout << "5: Display Details for Engine/Gear Oil Change " << endl;
        cout << "6: Calculate Total Bill for Engine/Gear Oil Change \n"
             << endl;

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Thank you for using the Program " << endl;
            break;

        case 1:
            if (count < size)
            {
                sptr[count] = new MaintainenceRepairing();
                try
                {
                    sptr[count]->acceptDetails();
                    count++;
                }
                catch (ServicingException &error)
                {
                    error.printErrorMessage();
                }
            }
            else
            {
                cout << "Cannot accept more Users " << endl;
            }
            break;

        case 2:
            for (int i = 0; i < count; i++)
            {
                if (typeid(*sptr[i]) == typeid(MaintainenceRepairing))
                {
                    sptr[i]->displayDetails();
                }
                cout << endl;
            }

            break;

        case 3:
            for (int i = 0; i < count; i++)
            {
                if (typeid(*sptr[i]) == typeid(MaintainenceRepairing))
                {
                    sptr[i]->calculateTotalBill();
                }
                cout << endl;
            }
            break;

        case 4:
            if (count < size)
            {
                sptr[count] = new EngineOilChange();
                try
                {
                    sptr[count]->acceptDetails();
                    count++;
                }
                catch (ServicingException &error)
                {
                    error.printErrorMessage();
                }
            }
            else
            {
                cout << "Cannot Accept More Users " << endl;
            }
            break;

        case 5:
            for (int i = 0; i < count; i++)
            {
                if (typeid(*sptr[i]) == typeid(EngineOilChange))
                {
                    sptr[i]->displayDetails();
                }
                cout << endl;
            }
            break;

        case 6:
            for (int i = 0; i < count; i++)
            {
                if (typeid(*sptr[i]) == typeid(EngineOilChange))
                {
                    sptr[i]->calculateTotalBill();
                }
                cout << endl;
            }
            break;

        default:
            cout << "Invalid Choice " << endl;
            break;
        }

    } while (choice != 0);

    for (int i = 0; i < count; i++)
    {
        delete sptr[i];
        // sptr[i] = NULL;
    }

    return 0;
}
