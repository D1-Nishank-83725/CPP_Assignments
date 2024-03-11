#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int top = -1;
    int size;

public:
    // Parameterless Constructor
    Stack()
    {
        arr = new int[5];
    }

    // Parameterized Constructor
    Stack(int size)
    {
        // cin >> size;
        this->size = size;
        arr = new int[size];
    }

    // Destructor
    ~Stack()
    {
        delete[] arr;
    }

    void printElementsOfStack()
    {
        cout << "Elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void pushElementToStack(int value)
    {
        if (checkIfStackIsFull())
        {
            cout << "Stack Overflow! " << endl;
        }
        else
        {
            cout << "Enter the Element you want to push in Stack: ";
            cin >> value;
            top++;
            arr[top] = value;
            cout << value << " successfully Pushed" << endl;
        }
    }

    void popElementFromStack()
    {
        if (checkIfStackIsEmpty())
        {
            cout << "Stack Underflow! " << endl;
        }
        else
        {
            cout << arr[top] << " successfully Popped" << endl;
            arr[top] = 0;
            top--;
        }
    }

    void peekTopElementOfStack()
    {
        if (checkIfStackIsEmpty())
        {
            cout << "Nothing to Peek to, Stack is Empty " << endl;
        }
        cout << "The element at top is: " << arr[top] << endl;
    }

    bool checkIfStackIsFull()
    {
        if (top == size - 1)
        {
            cout << "Stack is Full" << endl;
            return true;
        }

        else
        {
            cout << "Stack is NOT Full, still space for elements" << endl;
            return false;
        }
    }

    bool checkIfStackIsEmpty()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return true;
        }
        else
        {
            cout << "Stack is NOT Empty, you can still pop and peek elements out of stack" << endl;
            return false;
        }
    }
};

int main()
{
    int size;
    cout << "Enter the size of Array you want: ";
    cin >> size;

    Stack s1(size);

    int choice;
    int value;
    cout << endl;
    cout << "Stack Implementation" << endl;

    do
    {
        cout << "\n0: EXIT " << endl;
        cout << "1: Print Elements of Stack " << endl;
        cout << "2: Push Elements to Stack " << endl;
        cout << "3: Pop Element out of Stack " << endl;
        cout << "4: Peek Top ELement of Stack " << endl;
        cout << "5: Check if Stack is Empty " << endl;
        cout << "6: Check if Stack is Full \n"
             << endl;

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Thank you for using the Program" << endl;
            break;

        case 1:
            s1.printElementsOfStack();
            break;

        case 2:
            s1.pushElementToStack(value);
            break;

        case 3:
            s1.popElementFromStack();
            break;

        case 4:
            s1.peekTopElementOfStack();
            break;

        case 5:
            s1.checkIfStackIsEmpty();
            break;

        case 6:
            s1.checkIfStackIsEmpty();
            break;

        default:
            cout << "Invalid Choice !! " << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}
