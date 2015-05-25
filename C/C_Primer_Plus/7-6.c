#include <stdio.h>
int main(void)
{
    char present, former = 0;
    int i = 0;

    while((present = getchar()) != '#')
    {
        putchar(present);
        if(former == 'e' && present == 'i')
            i++;
        former = present;
    }
    printf("times of 'ei':%d", i);

    return 0;
}
