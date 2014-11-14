#include <stdio.h>
#include <ctype.h>

int loc(char);
int main(void)
{
    char ch;
    int location;

    printf("Please input some characters:");
    while((ch = getchar()) != EOF)
    {
        while(ch == '\n')
            continue;
        location = loc(ch);
        if(location == -1)
            printf(" NOT CHAR! ");
        else
            printf("%4d", location);
    }

    return 0;
}

int loc(char ch)
{
    int location;
    if(islower(ch))
        location = ch - 96;
    else if(isupper(ch))
        location = ch - 64;
    else
        location = -1;

    return location;
}
