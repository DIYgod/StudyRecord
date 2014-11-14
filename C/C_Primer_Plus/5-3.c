#include <stdio.h>

int main(void)
{
    int day, week, left;

    printf("Enter the number of days(<0 to quit):");
    scanf("%d", &day);
    while(day > 0)
    {
        week = day / 7;
        left = day % 7;
        printf("%d days is %d weeks and %d days\n", day, week, left);
        printf("Enter the number of the days(<0 to quit):");
        scanf("%d", &day);
    }
    return 0;
}
