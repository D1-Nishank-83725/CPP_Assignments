#include <iostream>

class Base
{
public:
    static int staticMember;
};

int Base::staticMember = 100;

class Derived : public Base
{
};

int main()
{
    Derived::staticMember = 200;
    std::cout << "Value of staticMember in Base: " << Base::staticMember << std::endl;
    std::cout << "Value of staticMember in Derived: " << Derived::staticMember << std::endl;

    // Derived::staticMember = 42;

    std::cout << "Value of staticMember in Base after modification: " << Base::staticMember << std::endl;
    std::cout << "Value of staticMember in Derived after modification: " << Derived::staticMember << std::endl;

    return 0;
}
