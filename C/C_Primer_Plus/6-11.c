#include <stdio.h>
#include <math.h>

int main(void)
{
    int max;
    float i, sum, count;

    printf("Enter the count:");
    scanf("%d", &max);


    for(sum = 0, count = 1.0; count <= max; count++)
    {
        i = 1.0 / count;
        sum += i;
    }
    printf("1.0 + 1.0/2.0 + 1.0/3.0 + ... = %f\n", sum);

    for(sum = 0, count =1.0; count <= max; count++)
    {
        i = pow(-1.0, count - 1.0) * 1.0 / count;
        sum += i;
    }
    printf("1.0 - 1.0/2.0 + 1.0/3.0 + ... = %f\n", sum);

    return 0;
}
