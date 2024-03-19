/*Q1. Implement a Stack class using C++ templates. Test stack operations on Stack<int>,
Stack<double> and Stack<Box>*/

#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    T *arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        arr = new T[size];
        top = -1;
    }
    bool isEmpty()
    {
        if (top < -1)
            return true;
        return false;
    }
    bool isFull()
    {
        if (top >= size - 1)
            return true;
        return false;
    }
    bool push(T element)
    {
        if (isFull)
        {
            cout << "\nStack OverFlow..." << endl;
            return false;
        }
        arr[++top] = element;
        return true;
    }
    T pop()
    {
        if (isEmpty)
        {
            cout << "\nStack UnderFlow..." << endl;
            return false;
        }
        return arr[top--];
    }
    T peek()
    {
        if (isEmpty)
        {
            cout << "\nStack is empty..." << endl;
            return false;
        }
        return arr[top];
    }
    void display()
    {
        cout << "\nThe stack elements : " << endl;

        for (int i = top; i <= 0; i--)
        {
            cout << arr[i] << "\t";
        }
    }
};
class Box
{
private:
    int length;
    int breadth;
    int height;

public:
    void accept()
    {
        cout << "\nEnter length :";
        cin >> length;
        cout << "\nEnter breadth :";
        cin >> breadth;
        cout << "\nEnter height :";
        cin >> height;
    }
    void display()
    {
        cout << "\nLength = " << length << endl;
        cout << "Breadth = " << breadth << endl;
        cout << "Height = " << height << endl;
    }
};
int menu()
{
    int choice;
    cout << "\n******Menu******" << endl;
    cout << "\n0.Exit" << endl;
    cout << "\n1.Push element" << endl;
    cout << "\n2.Pop element" << endl;
    cout << "\n3.Peek element" << endl;
    cout << "\n4.Display stack" << endl;
    cout << "\nEnter your choice : ";
    cin >> choice;
    return choice;
}
int main()
{
    int choice, ch;
    Stack<int> s1(5);
    int data;
    Stack<double> s2(5);
    double data2;
    Stack<char> s3(5);
    char data3;
    Stack<Box> s4(5);
    Box b;
    cout << "\n******Menu******" << endl;
    cout << "\n*1.INT DATA" << endl;
    cout << "\n2.DOUBLE DATA" << endl;
    cout << "\n3.CHARACTER DATA" << endl;
    cout << "\n4.BOX DATA" << endl;
    cout << "\n0.EXIT" << endl;

    cout << "\nWhich data do you want to store in stack :";
    cin >> ch;

    while (ch != 0)
    {
        switch (ch)
        {
        case 1:

            while ((choice = menu()) != 0)
            {
                switch (choice)
                {
                case 1:
                    cout << "Enter the data to push on stack :";
                    cin >> data;
                    s1.push(data);
                    break;
                case 2:
                    s1.pop();
                    break;
                case 3:
                    s1.peek();
                    break;
                case 4:
                    s1.display();
                    break;
                default:
                    cout << "\nWrong choice..." << endl;
                    break;
                }
            }
            break;
        case 2:

            while ((choice = menu()) != 0)
            {
                switch (choice)
                {
                case 1:
                    cout << "Enter the data to push on stack :";
                    cin >> data2;
                    s2.push(data2);
                    break;
                case 2:
                    s2.pop();
                    break;
                case 3:
                    s2.peek();
                    break;
                case 4:
                    s2.display();
                    break;
                default:
                    cout << "\nWrong choice..." << endl;
                    break;
                }
            }
            break;
        case 3:

            while ((choice = menu()) != 0)
            {
                switch (choice)
                {
                case 1:
                    cout << "Enter the data to push on stack :";
                    cin >> data3;
                    s3.push(data3);
                    break;
                case 2:
                    s3.pop();
                    break;
                case 3:
                    s3.peek();
                    break;
                case 4:
                    s3.display();
                    break;
                default:
                    cout << "\nWrong choice..." << endl;
                    break;
                }
            }
            break;
        case 4:

            while ((choice = menu()) != 0)
            {
                switch (choice)
                {
                case 1:
                    cout << "Enter the data to push on stack :";
                    b.accept();
                    s4.push(b);
                    break;
                case 2:
                    s4.pop();
                    break;
                case 3:
                    s4.peek();
                    break;
                case 4:
                    s4.display();
                    break;
                default:
                    cout << "\nWrong choice..." << endl;
                    break;
                }
            }

            break;
        }
    }
    return 0;
}