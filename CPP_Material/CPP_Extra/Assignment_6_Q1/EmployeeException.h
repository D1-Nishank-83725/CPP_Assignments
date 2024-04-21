#ifndef EMPLOYEE_EXCEPTION_H
#define EMPLOYEE_EXCEPTION_H

#include <iostream>
using namespace std;

// Make Individual Objects and check
// Employee Pointer : Class rest wali
// Can you have those functionalites using the

// #include "EmployeeException.h"

class EmployeeException
{

private:
    string message;

public:
    EmployeeException();
    EmployeeException(string message);
    void printErrorMessage();
    
};



#endif 



