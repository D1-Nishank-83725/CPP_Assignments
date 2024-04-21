#include <iostream>
using namespace std;

class Student
{
private:
    int marks;
    string name;

public:

    int getMarks()
    {
        return this->marks;
    }
    void setMarks(int marks)
    {
        this->marks = marks;
    }

    string getName()
    {
        return this->name;
    }
    void setName(string name)
    {
        this->name = name;
    }
};
int main()
{

    return 0;
}