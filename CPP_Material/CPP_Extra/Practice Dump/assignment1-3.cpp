#include <iostream>
using namespace std;













// class Stack
// {

// private:
//     int *arr;
//     int top = -1;
//     int size;

// public:
//     Stack()
//     {
//         arr = new int[5];
//     }

//     Stack(int size)
//     {
//         // This is an Important step -input liya hua size jo hai vo assign karta hai to the variable size, jisse dynamically allocated array banta hai
//         this->size = size;
//         arr = new int[size];
//     }

//     ~Stack()
//     {
//         delete[] arr;
//     }

//     void print()
//     {
//         cout << " Elements of Array: ";
//         for (int i = 0; i < size; i++)
//         {
//             cout << arr[i] << " ";
//         }
//     }

//     void push(int value)
//     {
//         if (isFull())
//         {
//             cout << "Stack Overflow!" << endl;
//         }
//         else
//         {
//             cout << "Enter value to Push: ";
//             cin >> value;
//             top++;
//             arr[top] = value;
//         }
//     }

//     void pop()
//     {
//         if (isEmpty())
//         {
//             cout << "Stack Underflow! " << endl;
//         }
//         else
//         {
//             arr[top] = 0;
//             top--;
//         }
//     }

//     void peek()
//     {
//         cout << "Element at top to peek is: " << arr[top] << endl;
//     }

//     bool isEmpty()
//     {

//         if (top == -1)
//         {
//             cout << "Stack is Empty" << endl;
//             return true;
//         }
//         else
//         {
//             cout << "Stack not Empty" << endl;
//             return false;
//         }
//     }
//     bool isFull()
//     {
//         if (top == size - 1)
//         {
//             cout << "Stack is Full" << endl;
//             return true;
//         }
//         else
//         {
//             cout << "Can push elements to Stack" << endl;
//             return false;
//         }
//     }
// };

// int main()
// {
//     int size;
//     cout << "Enter the Size of Stack you want: " << endl;
//     cin >> size;

//     Stack s1(size);
//     int choice;

//     do
//     {
//         cout << "\n\n0: EXIT" << endl;
//         cout << "1: Print Elements of Stack " << endl;
//         cout << "2: Push Element to Stack " << endl;
//         cout << "3: Pop Element from Stack " << endl;
//         cout << "4: Check if Stack is Empty" << endl;
//         cout << "5: Check if Stack is Full" << endl;
//         cout << "6: Peek Top Element\n\n"
//              << endl;

//         cin >> choice;

//         switch (choice)
//         {
//         case 0:
//             cout << "Thanks" << endl;
//             break;

//         case 1:
//             s1.print();
//             break;

//         case 2:
//             s1.push(size);
//             break;

//         case 3:
//             s1.pop();
//             break;

//         case 4:
//             s1.isEmpty();
//             break;

//         case 5:
//             s1.isFull();
//             break;

//         case 6:
//             s1.peek();
//             break;

//         default:
//             cout << "Invaid Choice!" << endl;
//             break;
//         }

//     } while (choice != 0);

//     return 0;
// }










// Assignment 3 Question 1 Done - Ask for any optimization from Atharva Bhai

// class Time
// {
// private:
//     int hours;
//     int minutes;
//     int seconds;

// public:
//     Time()
//     {
//         hours = 1;
//         minutes = 1;
//         seconds = 1;
//     }

//     Time(int hours, int minutes, int seconds)
//     {
//         this->hours = hours;
//         this->minutes = minutes;
//         this->seconds = seconds;
//     }

//     int getHour()
//     {
//         return hours;
//     }

//     int getMinutes()
//     {
//         return minutes;
//     }

//     int getSeconds()
//     {
//         return seconds;
//     }

//     void setHour(int hours)
//     {
//         this->hours = hours;
//     }

//     void setMinutes(int minutes)
//     {
//         this->minutes = minutes;
//     }

//     void setSeconds(int seconds)
//     {
//         this->seconds = seconds;
//     }

//     void printTime()
//     {
//         cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
//     }
// };

// int main()
// {
//     int size, value;
//     cout << "Enter the size of the array you want" << endl;
//     cin >> size;
//     Time *arr = new Time[size];

//     arr[0].printTime();

//     cin >> value;
//     arr[1].setHour(value);
//     cin >> value;
//     arr[1].setMinutes(value);
//     cin >> value;
//     arr[1].setSeconds(value);
//     arr[1].printTime();
//     arr[2].printTime();

//     return 0;
// }

// Assignment 2 Q1 Done, kyuki tab bada confuse ho gaya tha mai

// class Box
// {
// private:
//     int length;
//     int width;
//     int height;

// public:
//     Box() : Box(1, 1, 1) {}

//     Box(int length, int width, int height)
//     {
//         this->length = length;
//         this->width = width;
//         this->height = height;
//     }

//     void acceptParaForVolume()
//     {
//         cout << "Enter Length: ";
//         cin >> length;
//         this->length = length;

//         cout << "Enter Width: ";
//         cin >> width;
//         this->width = width;

//         cout << "Enter Height: ";
//         cin >> height;
//         this->height = height;
//     }

//     void calcVolume()
//     {
//         cout << "Volume: " << length * width * height << endl;
//     }
// };

// int main()
// {

//     Box b1;
//     b1.calcVolume();
//     b1.acceptParaForVolume();
//     b1.calcVolume();

//     return 0;
// }

// // Assignment 1 Q2 Class , Q1 not needed as it is in C , q3 is similar to q2

// class Date
// {
// private:
//     int day;
//     int month;
//     int year;

// public:
//     Date() : Date(1, 1, 1) {}

//     Date(int day, int month, int year)
//     {
//         ;
//         this->day = day;
//         this->month = month;
//         this->year = year;
//     }

//     void initDate()
//     {
//         cout << "Initialized Date: " << day << "/" << month << "/" << year << endl;
//     }

//     void acceptDateFromConsole()
//     {
//         cout << "Enter the Date: ";
//         cin >> day >> month >> year;
//     }

//     void printDateOnConsole()
//     {
//         cout << "Date: " << day << "/" << month << "/" << year << endl;
//     }
// };

// int main()
// {

//     Date d1;
//     d1.initDate();
//     d1.acceptDateFromConsole();
//     d1.printDateOnConsole();
//     return 0;
// }