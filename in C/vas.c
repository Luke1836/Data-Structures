#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Date{
    int day; int month; int year;
} date;

bool isLeap(int year){
    if((year%4==0 && year%100!=0)||(year%400==0)){
        return true;
    }
}

bool isValid(int day,int month, int year){
    if(month<1 || month>12){
        return false;
    }
    if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
        if(day<1 || day>31){
            return false;
        }
    }
    if(month==4 || month==6 || month==9 || month==11){
        if(day<1 || day>30){
            return false;
        }
    }
    if(month==2){
        if(isLeap(year)){
            if(day<1 || day>29){
                return false;
            }
        }
        else{
            if(day<1 || day>28){
                return false;
            }
        }
    }

    else return true;
}

struct Date increment(struct Date date){
    date.day++;
    if(!isValid(date.day,date.month,date.year)){
        date.day=1;
        date.month++;
        if(!isValid(date.day,date.month,date.year)){
            date.month=1;
            date.year++;
        }
    }
    return date;
}

struct Date decrement(struct Date date){
    date.day--;
    if(!isValid(date.day,date.month,date.year)){
        if(date.month==1 || date.month==2 || date.month==4 || date.month==6 || date.month==8 || date.month==9 || date.month==11){
            date.day=31;
            date.month--;
            if(!isValid(date.day,date.month,date.year)){
                date.month=12;
                date.year--;
            }
        }
        else if(date.month==5 || date.month==7 || date.month==10 || date.month==12){
            date.day=30;
            date.month--;
        }
        else if(date.month==3){
            if(!isLeap(date.year)){
                date.day=28;
                date.month=2;
            }
            else if(isLeap(date.year)){
            date.day=29;
            date.month=2;
                
            }
        }
    }
    return date;
}

struct Date inc(struct Date date){
    int n;
    printf("enter n:");scanf("%d",&n);
    for(int i=0;i<n;i++){
        date=increment(date);
    }
    return date;
}

void main(){
    struct Date date;
    int ch;
    printf("Enter day, month, year:");scanf("%d %d %d",&date.day,&date.month,&date.year);
    
    while(1){
        printf("\n1.check date\n2.incerment date\n3.decrement date\n4.increment date by n days:...");scanf("%d",&ch);
        if(ch==1){
            if(isValid(date.day,date.month,date.year)){
                printf("date is valid");
            }
            else printf("date is not valid");
        }
        else if(ch==2){
            printf("\nincermented date:\n");
            date=increment(date);
            printf("\n%d/%d/%d",date.day,date.month,date.year);
        }
        else if(ch==3){
            printf("decremneted date:\n");
            date=decrement(date);
            printf("\n%d/%d/%d",date.day,date.month,date.year);
        }
        else if(ch==4){
            date=inc(date);
            printf("\n%d/%d/%d",date.day,date.month,date.year);
        }
        else exit(1);
    }
}