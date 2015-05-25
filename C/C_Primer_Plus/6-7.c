#include <stdio.h>

int main(void)
{
    float a, b, result;

    printf("Please input two floats:");

    while(scanf("%f %f", &a, &b) == 2)
    {
        result = (a - b) / (a * b);
        printf("%f\n", result);
        printf("Enter next pair(non-numeric to quit):");
    }

    return 0;
}
