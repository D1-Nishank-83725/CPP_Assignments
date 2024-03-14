#include <iostream>
using namespace std;

void factorial(int num)
{
    if (num < 0)
    {
        throw 1;
    }

    int factorial = 1;
    for (int i = 1; i <= num; i++)
    {
        factorial *= i;
    }

    cout << "Factorial of the Number is : " << factorial << endl;
}

int main()
{
    int num;
    cout << "Enter number for Factorial: ";
    cin >> num;
    try
    {
        factorial(num);
    }

    catch (...)
    {
        cout << "Number needs to be greater than 0" << endl;
    }

    return 0;
}
