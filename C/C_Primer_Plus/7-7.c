#include <stdio.h>
#define JI 10
#define JIA 1.5
#define SHUI1 0.15
#define SHUI2 0.2
#define SHUI3 0.25
#define SHUI300 BREAK1 * SHUI1
#define SHUI450 BREAK1 * SHUI1 + (BREAK2 - BREAK1) * SHUI2
#define BREAK 40
#define BREAK1 300
#define BREAK2 450

int main(void)
{
    double time, gz, shui, left;

    printf("Please input your working time in hour:");
    while(scanf("%lf", &time) == 1)
    {
        if(time > BREAK)
            time = (time - BREAK) * JIA + BREAK;

        gz = time * JI;

        if(gz <= BREAK1)
            shui = gz * SHUI1;
        else if(gz <= BREAK2)
            shui = SHUI300 + (gz - BREAK1) * SHUI2;
        else
            shui = SHUI450 + (gz - BREAK2) * SHUI3;

        left = gz - shui;

        printf("gz:%.1f, shui:%.1f, left:%.1f\n", gz, shui, left);
        printf("Please input another time(q to quit):");
    }

    return 0;
}
