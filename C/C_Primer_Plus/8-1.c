#include <stdio.h>

int main(void)
{
    int i = 0, ch;
    while((ch = getchar()) != EOF)
        i++;
    printf("%d characters read\n", i);

    return 0;
}
