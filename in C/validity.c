#include <stdio.h>

int isLeapYear(int);
int valid(int*, int*, int*);
void incrementOne(int*, int*, int*);
void decrementOne(int*, int*, int*);
void increment(int, int*, int*, int*);
void display(int*, int*, int*);

int main(void) 
{
    typedef struct {
        int day;
        int month;
        int year;
    } date;
    date e;
    int choice, wish;
    printf("Enter the date (dd/mm/yyyy)\n");
    scanf("%d%d%d", &e.day, &e.month, &e.year);
    do {
    printf("\t\t\t\t\tList\n1. Check for validity\n2. Increment day by One\n3. Decrement day by One.\n4. Increment date by n days.\nEnter your choice\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: int ans = valid(&(e.day), &(e.month), &(e.year));
                if(ans == 1)
                    {printf("The given date is valid!\n");
                    display(&(e.day), &(e.month), &(e.year));}
                else
                    {
                        printf("THe given year is not valid!\nSo no operations are possible\n");
                        display(&(e.day), &(e.month), &(e.year));
                        return(1);
                    }
                break;

        case 2: if(valid(&(e.day), &(e.month), &(e.year)) == 1)
                    {incrementOne(&(e.day), &(e.month), &(e.year));
                    display(&(e.day), &(e.month), &(e.year));}
                else 
                    {printf("Date is not valid!\n");
                    display(&(e.day), &(e.month), &(e.year));
                    return 1;}
                break;

        case 3: if(valid(&(e.day), &(e.month), &(e.year)) == 1)
                    {decrementOne(&(e.day), &(e.month), &(e.year));
                    display(&(e.day), &(e.month), &(e.year));}
                else 
                    {printf("Date is not valid!\n");
                    display(&(e.day), &(e.month), &(e.year));
                    return 1;}
                break;

        case 4: printf("Enter the value of n\n");
                int n;
                scanf("%d", &n);
                if(valid(&(e.day), &(e.month), &(e.year)) == 1)
                    {increment(n, &(e.day), &(e.month), &(e.year));
                    display(&(e.day), &(e.month), &(e.year));}
                else 
                    {printf("Date is not valid!\n");
                    display(&(e.day), &(e.month), &(e.year));
                    return 1;}
                break;

        default: printf("Invalid Choice!\n");
    }
    printf("Do you wish to continue (0/1)\n");
    scanf("%d", &wish);
    } while(wish == 1);
}
int isLeapYear(int year)
{   if((year % 400 == 0) || (year % 4 == 0 && year%100 != 0))
        return 1;
    else
        return 0;
}
int valid(int *day, int *month, int *year)
{   int y = *year;
    if(*day > 31 || *month > 12 || *month < 1 || *day < 1 || y < 1500)
        return 0;
    if(*month == 2)
    {   if(isLeapYear(y))
            if(*day <= 29)
                return 1;
            else
                return 0;
        else
            if(*day <= 28)
                return 1;
            else 
                return 0;}
    if(*month == 4 || *month == 6 || *month == 9 || *month == 11)
        if(*day <= 30)
            return 0;
        else 
            return 1;
    else    
        return 1;}

void display(int* day, int* month, int* year)
{printf("Date: %d / %d / %d\n", *day, *month, *year);}

void incrementOne(int *day, int *month, int *year)
{   *day = *day + 1;
    if(!(valid(day, month, year) == 1))
    {
        *day = 1;
        *month ++;
        if(!(valid(day, month, year) == 1))
            {*month = 1;
             *year++;
            }
    }
}
void decrementOne(int *day, int *month, int *year)
{   *day = *day - 1;
int y = *year;
    if(!valid(day, month, year))
    {
        if(*month == 2 || *month == 4 || *month == 6 || *month == 9 || *month == 11)
        {
            *day = 31;
            *month --;
        }
        else if(*month == 1)
        {
            *day = 31;
            *month =12;
            *year --;
        }
        else if(*month == 3)
        {
            if(isLeapYear(y))
            {
                *day = 29;
                *month--;
            }
            else{
                *day = 28;
                *month --;
            }
        }
        else{
            *day = 30;
            *month--;
        }
    }
}

void increment(int n, int *day, int *month, int *year) {
    int newDay = *day + n;
    int newMonth = *month;
    int newYear = *year;
    int arr[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(newYear)) {
        arr[2] = 29;}
    while (newDay > arr[newMonth]) {
        newDay -= arr[newMonth];
        newMonth++;
        if (newMonth > 12) {
            newMonth = 1;
            newYear++;
            if (isLeapYear(newYear)) {
                arr[2] = 29;
            } else {
                arr[2] = 28;
            }}}
    *day = newDay;
    *month = newMonth;
    *year = newYear;
}





