#include <stdio.h>
#define SIZE 8

int main(void)
{
    double num[SIZE], sum[SIZE];
    int index;

    printf("Please input 8 numbers:");
    for(index = 0; index < SIZE; index++)
        scanf("%lf", &num[index]);

    for(index = 0, sum[0] = num[0]; index < SIZE - 1; index++)
        sum[index + 1] = sum[index] + num[index + 1];

    for(index = 0; index < SIZE; index++)
        printf("%8.2lf", num[index]);
    printf("\n");

    for(index = 0; index < SIZE; index++)
        printf("%8.2lf", sum[index]);

    return 0;
}
