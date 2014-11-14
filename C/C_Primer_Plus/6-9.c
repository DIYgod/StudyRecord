#include <stdio.h>

int main(void)
{
    int lower, upper, i, sum;

    printf("Enter lower and upper integer limits:");
    scanf("%d %d", &lower, &upper);
    while(lower < upper)
    {
        for(i = lower, sum = 0; i <= upper; i++)
            sum += i * i;
        printf("The sums of the squares from %d to %d is %d\n", lower, upper, sum);

        printf("Enter next set of limits:");
        scanf("%d %d", &lower, &upper);
    }
    printf("Done\n");
    return 0;
}
