#include "EmployeeException.h"

EmployeeException::EmployeeException()
{
    cout << "Something went wrong " << endl;
}
EmployeeException::EmployeeException(string message)
{
    this->message = message;
}

void EmployeeException::printErrorMessage()
{
    cout << message << endl;
}