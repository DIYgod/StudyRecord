#include <stdio.h>

unsigned long fibonacci(int i);
int main(void)
{
    int i;
    unsigned long fib;
    printf("Please inter a number:");
    while(scanf("%d", &i) == 1)
    {
        fib = fibonacci(i);
        printf("Fibonacci:%lu\n", fib);
        printf("Please inter another number(q to quit):");
    }
    return 0;
}

unsigned long fibonacci(int i)
{
    unsigned long fib, fib1 = 1, fib2 = 1;
    int count = 1;

    if(i <= 2)
        fib = 1;
    else
        while(count <= i - 2)
        {
            fib = fib1 + fib2;
            fib1 = fib2;
            fib2 = fib;
            count++;
        }
    return fib;
}
