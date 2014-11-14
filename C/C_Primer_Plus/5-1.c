#include <stdio.h>

int main(void)
#define M_PER_H 60
{
    int minute, hour, left;
    printf("Convert minutes to hours and minutes!\n");
    printf("Enter the number of minutes(<=0 to quit):\n");
    scanf("%d", &minute);
    while(minute>0)
    {
        hour = minute / M_PER_H;
        left = minute % M_PER_H;
        printf("%d minute is %d hour and %d minute\n", minute, hour, left);
        printf("Enter next value(<=0 to quit):\n");
        scanf("%d", &minute);
    }
    return 0;
}
