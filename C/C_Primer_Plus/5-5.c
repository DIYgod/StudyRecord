#include <stdio.h>
int main(void)
{
    int count, sum, max;

    count = 0;
    sum = 0;
    printf("Please enter the number of max\n");
    scanf("%d", &max);
    while (count++ < max)
        sum = sum + count;
    printf("sum = %d\n", sum);

    return 0;
}
