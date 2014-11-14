#include <stdio.h>

void Temperatures(double);

int main(void)
{
    double fa;

    printf("Please input the Temperature:");

    while(scanf("%lf", &fa) == 1)
    {
        Temperatures(fa);
        printf("Please input the Temperature(not number to quit):");
    }

    printf("End\n");

    return 0;
}

void Temperatures(double num)
{
    const float FA_TO_CE1 = 1.8;
    const float FA_TO_CE2 = 32.0;
    const float CE_TO_KE = 273.16;
    double ce, ke;

    ce = FA_TO_CE1 * num +FA_TO_CE2;
    ke = ce + CE_TO_KE;

    printf("Celsius = %.2lf, Kelvin = %.2lf\n", ce, ke);

    return 0;
}
