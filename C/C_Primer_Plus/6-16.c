#include <stdio.h>
#define CASH 100
#define RATE 0.08
#define LESS 10

int main(void)
{
    int year = 0, money = CASH;

    while(money > 0)
    {
        year++;
        money += money * RATE;
        money -= LESS;
    }

    printf("Need %d years", year);

    return 0;
}
