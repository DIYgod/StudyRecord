#include <stdio.h>

char * istrchr(char * ar, char ch);

int main(void)
{
    char str[100];
    char * ar;
    char ch;
    printf("Please inter a string(q to quit):");
    gets(str);
    while(strcmp(str,"q"))
    {
        printf("Please inter the character you want:");
        ch = getchar();
        while(getchar() != '\n')
            continue;
        ar = istrchr(str, ch);
        printf("str:%p, ar:%p\n", str, ar);
        printf("Please inter a string(q to quit):");
        gets(str);
    }
    return 0;
}

char * istrchr(char * ar, char ch)
{
    char * loc;
    loc = NULL;
    while(*ar)
    {
        if(*ar == ch)
        {
            loc = ar;
            break;
        }
        ar++;
    }
    return loc;
}
