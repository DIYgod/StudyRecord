#include <stdio.h>
#define MAX 40
char * opposit(const char * ch);

int main(void)
{
    char ch[MAX];
    char * oppo;
    printf("Enter some words:");
    while(gets(ch) && ch[0] != '\0')
    {
        oppo = opposit(ch);
        puts(oppo);
        printf("Enter some word again:");
    }
    return 0;
}

#include <string.h>
char * opposit(const char * ch)
{
    char op1[MAX], op2[MAX];
    char * oppo;
    char * result;
    oppo = op1;
    result = op2;
    int slen, wlen, i;
    slen = strlen(ch);
    for(i = 0; i < slen; i++)
        *(oppo + i) = *(ch + slen - 2 - i);
    *(oppo + i + 1) = '\0';
    strcpy(op2, op1);
    while(*oppo != '\0')
    {
        for(wlen = 0; *oppo != ' ' && *oppo != '\0'; oppo++)
            wlen++;
        for(i = 0; i < wlen; i++)
            *(result + i) = *(oppo - 1 - i);
        oppo++;
    }

    return result;
}
