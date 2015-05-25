#include <stdio.h>

int main(void)
{
    int ck = 0, ch =0, co = 0;
    char c;

    while((c = getchar()) != '#')
    {
        if(c == ' ')
            ck++;
        else if(c == '\n')
            ch++;
        else
            co++;
    }
    printf("ck = %d, ch = %d, co = %d", ck, ch, co);

    return 0;
}
