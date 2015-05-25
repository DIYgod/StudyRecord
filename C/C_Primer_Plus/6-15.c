#include <stdio.h>
#include <math.h>
#define CASH 100
#define DA 0.1
#define DE 0.05

int main(void)
{
    int year = 0;
    float da = CASH, de = CASH;
    while(da >= de)
    {
        year++;
        da += CASH * DA;
        de += de * DE;
    }
    printf("Daphne:%.2f, Derodre:%.2f, year:%d\n", da, de, year);

    return 0;
}
