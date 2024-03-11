#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrDate)
{
    //Here, I have taken a Default date as 1/1/2000, for the purpose of initialization
    ptrDate->day = 1;
    ptrDate->month = 1;
    ptrDate->year = 2000;
}

void printDateOnConsole(struct Date *ptrDate)
{
    printf("\nDate: %d-%d-%d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

void acceptDateFromConsole(struct Date *ptrDate)
{
    printf("\nEnter the Date: \n");
    scanf("%d%d%d", &ptrDate->day, &ptrDate->month, &ptrDate->year);
}

int main()
{

    struct Date d1;
    initDate(&d1);
    int choice;

    printf("Program to Initialize, Accept and Print Date\n");

    do
    {

        printf("\n0: EXIT\n");
        printf("1: Initialize Date to Default(1-1-2000)\n");
        printf("2: Accept Date\n");
        printf("3: Print Date\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            break;
        case 1:
            initDate(&d1);
            break;
        case 2:
            acceptDateFromConsole(&d1);
            break;
        case 3:
            printDateOnConsole(&d1);
            break;

        default:
            printf("Invalid Choice!");
            break;
        }
    } while (choice != 0);

    return 0;
}
