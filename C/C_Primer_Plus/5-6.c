#include <stdio.h>
int main(void)
{
    int count, sum, max, add;

    count = 0;
    sum = 0;
    printf("Please enter the number of max\n");
    scanf("%d", &max);
    while (count++ < max)
    {
        add = count * count;
        sum = sum + add;
    }
    printf("sum = %d\n", sum);

    return 0;
}
