#include <stdio.h>

int main(void)
{
    int i, j;

    for (i = 1; i <= 6; i++)
    {
        for (j = 1; j <= i; j++)
            printf("%c", 'F' - j + 1);
        printf("\n");
    }

    return 0;
}
