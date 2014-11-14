#include <stdio.h>
#define JIA 1.5
#define SHUI1 0.15
#define SHUI2 0.2
#define SHUI3 0.25
#define SHUI300 BREAK1 * SHUI1
#define SHUI450 BREAK1 * SHUI1 + (BREAK2 - BREAK1) * SHUI2
#define BREAK 40
#define BREAK1 300
#define BREAK2 450
#define RATE1 8.75
#define RATE2 9.33
#define RATE3 10.00
#define RATE4 11.20

int main(void)
{
    double ji, i, time, gz, shui, left;
    int rate;
    for(i = 0; i <= 65; i++)
        printf("*");
    printf("\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $%.2f/hr\t\t\t2) $%.2f/hr\n", RATE1, RATE2);
    printf("3) $%.2f/hr\t\t\t4) $%.2f/hr\n", RATE3, RATE4);
    printf("5) quit\n");
    for(i = 0; i <= 65; i++)
        printf("*");
    printf("\n");

    while(scanf("%d", &rate) == 1 && rate != 5)
    {
        if(rate >= 1 && rate < 5)
        {
        switch(rate)
        {
        case 1:
            ji = RATE1;
            break;
        case 2:
            ji = RATE2;
            break;
        case 3:
            ji = RATE3;
            break;
        case 4:
            ji = RATE4;
        }

        printf("Please input your working time:");
        scanf("%lf", &time);

        if(time > BREAK)
            time = (time - BREAK) * JIA + BREAK;

        gz = time * ji;

        if(gz <= BREAK1)
            shui = gz * SHUI1;
        else if(gz <= BREAK2)
            shui = SHUI300 + (gz - BREAK1) * SHUI2;
        else
            shui = SHUI450 + (gz - BREAK2) * SHUI3;

        left = gz - shui;

        printf("gz:%.1f, shui:%.1f, left:%.1f\n", gz, shui, left);
        printf("Enter another number corresponding to the desired pay rate or action(q to quit):");
        }
        else
            printf("Please iput right order!\n");
    }

    return 0;
}
