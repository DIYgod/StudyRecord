#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MONTH 12

struct imonth {
    char name[10];
    char abbrev[4];
    int days;
    int monumb;
};

const struct imonth months[MONTH] = {
{"January", "Jan", 31, 1},
{"February", "Feb", 28, 2},
{"March", "Mar", 31, 3},
{"April", "Apr", 30, 4},
{"May", "May", 31, 5},
{"June", "Jun", 30, 6},
{"July", "Jul", 31, 7},
{"August", "Aug", 31, 8},
{"September", "Sep", 30, 9},
{"October", "Oct", 31, 10},
{"November", "Nov", 30, 11},
{"December", "Dec", 31, 12}
};

int daynum(int date, int month, int year);
int main(void)
{
    int date, month = 0, year, days, i;
    char intmonth[10];

    puts("Enter the date");
    if(scanf("%d", &date) != 1 || date <= 0 || date > 31)
    {
        puts("Input error!");
        exit(1);
    }

    puts("Enter the month");
    scanf("%s", &intmonth);
    for(i = 0; i < MONTH; i++)
        if(strcmp(intmonth, months[i].name) || strcmp(intmonth, months[i].abbrev) || (int)intmonth == months[i].monumb)
        {
            month = i + 1;
            break;
        }
    if(month <= 0 || month > 12)
    {
        puts("Input error!");
        exit(2);
    }

    puts("Enter the year");
    if(scanf("%d", &year) != 1 || year <= 0)
    {
        puts("Input error!");
        exit(3);
    }

    days = daynum(date, month, year);

    printf("There is %d days to %d/%d/%d", days, date, month, year);

    return 0;
}

int daynum(int date, int month, int year)
{
    int days, i;

    for(i = 0; i < month; i++)
        days += months[i].days;

    return days;
}
