#include <stdio.h>
#define SIZE 8
int main(void)
{
    int i = 0;
    char c;
    while((c = getchar()) != '#')
    {
        printf("%c %d   ", c, c);
        i++;
        if(i % SIZE == 0)
            printf("\n");
    }

    return 0;
}
