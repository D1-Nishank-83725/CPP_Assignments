#include <iostream>
#include <vector>
using namespace std;

class Course
{
private:
    int id;
    string courseName;
    double fees;

public:
    int getId()
    {
        return this->id;
    }

    void setId(int id)
    {
        this->id = id;
    }

    string getCourseName()
    {
        return this->courseName;
    }
    void setCourseName(string courseName)
    {
        this->courseName = courseName;
    }

    double getFees()
    {
        return this->fees;
    }
    void setFees(double fees)
    {
        this->fees = fees;
    }

    void acceptData()
    {

        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Course Name: ";
        cin >> courseName;
        cout << "Enter Fees: ";
        cin >> fees;
    }

    void displayData()
    {

        cout << "ID: " << id << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Fees: " << fees << endl;
    }
};

class Student
{
private:
    int rollno;
    string name;
    vector<Course> courseList;

public:
    int getRollno()
    {
        return this->rollno;
    }

    void setRollno(int rollno)
    {
        this->rollno = rollno;
    }

    string getName()
    {
        return this->name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void acceptData()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> rollno;
    }

    void displayData()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollno << endl;
        for (int i = 0; i < courseList.size(); i++)
        {
            courseList[i].displayData();
        }
    }

    void addCourse()
    {

        // int noOfCourses;
        // cout << "Enter the Number of Courses you want to Enroll For: " << endl;
        // cin >> noOfCourses;

        // for (int i = 0; i < noOfCourses; i++)
        // {

        Course c;
        c.acceptData();
        courseList.push_back(c);
        // Course *cptr;
        // cptr = new Course();
        // cptr->acceptData();
        // courseList.push_back(*cptr);
        // }
    }
};

int findStudent(vector<Student> &obj)
{
    int rollNo;
    cout << "Enter Roll Number to display Student Data: ";
    cin >> rollNo;
    for (int i = 0; i < obj.size(); i++)
    {
        if (obj[i].getRollno() == rollNo)
        {
            // obj[i].displayData();
            return i;
        }
    }
    return -1;
}
int main()
{

    int choice, noOfCourses, rollNo;
    Student S;
    vector<Student> studentList;

    do
    {
        cout << "\n0: Exit " << endl;
        cout << "1: Accept Student" << endl;
        cout << "2: Accept Courses " << endl;
        cout << "3: Display Student and Courses Enrolled  \n"
             << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Thank you for using the Program " << endl;
            break;

        case 1:
            S.acceptData();
            studentList.push_back(S);
            break;

        case 2:
            int rollNo;
            cout << "Enter the Roll Number: ";
            cin >> rollNo;

            for (int i = 0; i < studentList.size(); i++)
            {
                if (studentList[i].getRollno() == rollNo)
                {
                    studentList[i].addCourse();
                }
                else
                {
                    cout << "Invalid Choice!" << endl;
                }
            }

            // findStudent(studentList);
            break;

        case 3:
            int i;
            i = findStudent(studentList);
            // for (int i = 0; i < studentList.size(); i++)
            // {
            //     if (studentList[i].getRollno() == result)
            //     {
            //         studentList[i].displayData();
            //                     }
            // }
            if (i != -1)
            {
                studentList[i].displayData();
            }
            else
            {
                cout << "Invalid Roll Number Entered ";
            }

            break;

        default:
            cout << "Invalid Choice!" << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}