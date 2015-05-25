#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    unsigned long n, a, b;
    bool isprime = 1;
    printf("Pleae input an integer for analysis:");
    while(scanf("%lu", &n) == 1)
    {
        for(a = 2; a <= n; a++)
        {
            for(b = 2; (b * b) <= a; b++)
            {
                if(a % b == 0)
                   isprime = 0;
            }
            if(isprime == 1)
                printf("%lu  ", a);
            isprime = 1;
        }
        printf("\nPleae input another integer for analysis(q to quit):");
    }
    return 0;
}
