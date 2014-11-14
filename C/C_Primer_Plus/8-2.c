#include <stdio.h>

void out(int ch);
int main(void)
{
    int ch, i = 1;

    printf("Please input some characters\n");
    while((ch = getchar()) != EOF)
    {
        out(ch);
        printf(" %d  ", ch);

        i++;
        if(i == 10)
        {
            printf("\n");
            i = 1;
        }
    }

    return 0;
}

void out(int ch)
{
    if(ch == 13)
        printf("\\n");
    else if(ch == 9)
        printf("\\t");
    else if(ch <= 31)
        printf("^ %c", ch + 64);
    else
        putchar(ch);

    return 0;
}
