#include <stdio.h>

int main(void)
{
    int num, time;

    printf("Enter a number:");
    scanf("%d", &num);
    time = 0;

    while(time < 11)
    {
        printf("%4d", num + time);
        time++;
    }

    return 0;
}
