#include <iostream>
using namespace std;

class Student
{

private:
    string name;
    char gender;
    int rollno;
    int *marksarr;

public:
    Student() : Student("", '\0', 0) {}

    Student(string name, char gender, int rollno)
    {
        this->name = name;
        this->gender = gender;
        this->rollno = rollno;
    }

    int getRollno()
    {
        return rollno;
    }

    void acceptStudent()
    {

        cout << "Enter Name: " << endl;
        cin >> name;

        cout << "Enter Gender: " << endl;
        cin >> gender;

        cout << "Enter Roll Number: " << endl;
        cin >> rollno;

        marksarr = new int[3];

        for (int i = 0; i < 3; i++)
        {
            cout << "Enter Marks of Subject " << i + 1 << endl;
            cin >> marksarr[i];
        }
    }

    void printStudent()
    {

        cout << "\n\nName                : " << name << endl;
        cout << "Gender              : " << gender << endl;
        cout << "Roll Number         : " << rollno << endl;
        cout << "Percentage of Marks : ";
        cout << getPercentage();
        cout << " ( ";
        for (int i = 0; i < 3; i++)
        {
            cout << marksarr[i] << " ";
        }
        cout << ")\n\n";

        // cout << "Enter Marks of 3 Subjects: ";
    }

    int getPercentage()
    {
        int percentage;
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += marksarr[i];
        }
        percentage = sum / 3;
        return percentage;
    }
};

int printSpecificRollNoStudentDetails(Student *arr[], int rollno, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (rollno == arr[i]->getRollno())
        {
            return rollno;
        }
    }
    cout << "Student not Present! " << endl;
}

void sortUsingRollNo(Student *arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i]->getRollno() > arr[j]->getRollno())
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    int size;
    cout << "Enter the Number of Students: ";
    cin >> size;
    // Student *studentptr = new Student[size];

    // Dynamically Allocated Array of Pointer Declaration

    Student *arr[size];

    // Dynamically Allocated Array of Pointer Defintion

    for (int i = 0; i < size; i++)
    {
        arr[i] = new Student;
    }

    int choice;
    int rollno;

    do
    {
        cout << "\n\n0:  EXIT " << endl;
        cout << "1: Accept Student: " << endl;
        cout << "2: Print Student: " << endl;
        cout << "3: Sort Students according to Roll Number: " << endl;
        cout << "4: Search Student by entering Roll Number\n"
             << endl;

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Thank you for using the Program" << endl;
            break;

        case 1:
            for (int i = 0; i < size; i++)
            {
                cout << "Enter the Data for Student " << i + 1 << endl
                     << endl;
                // Remember you did error here
                //  studentptr->acceptStudent(); will be wrong as it will point to the last student

                arr[i]->acceptStudent();
            }

            break;

        case 2:
            for (int i = 0; i < size; i++)
            {
                arr[i]->printStudent();
            }

            break;

        case 3:
            sortUsingRollNo(arr, size);
            break;

        case 4:
            cout << "Search Student using Roll Number: ";
            cin >> rollno;
            cout << "Roll Number found at Position: ";

            cout << printSpecificRollNoStudentDetails(arr, rollno, size);

            break;

        default:
            cout << "Invalid Choice!" << endl;
            break;
        }

    } while (choice != 0);
}
