#include <stdio.h>

float result(float, float);

int main(void)
{
    float a, b;

    printf("Please input two floats:");

    while(scanf("%f %f", &a, &b) == 2)
    {
        printf("%f\n", result(a, b));
        printf("Enter next pair(non-numeric to quit):");
    }

    return 0;
}

float result(float a, float b)
{
    float i;
    i = (a - b) / (a * b);

    return i;
}
