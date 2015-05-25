#include <stdio.h>

float cube(float);

int main(void)
{
    float i;

    printf("Please enter a number:");
    scanf("%f", &i);
    printf("Cube of the number is %f\n", cube(i));

    return 0;
}

float cube(float number)
{
    return number * number * number;
}
