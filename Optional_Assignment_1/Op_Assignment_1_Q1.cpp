#include <iostream>
using namespace std;

class Matrix
{
private:
    int row;
    int col;
    int size;

public:
    Matrix()
    {
        row = 2;
        col = 2;
    }

    Matrix(int size)
    {
        this->size = size;
    }
};

int main()
{
    int size;
    cout << "Enter Dimension of the Matrix you want: ";
    cin >> size;
    Matrix m1(size);

    return 0;
}
