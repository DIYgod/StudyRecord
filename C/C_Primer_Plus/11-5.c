#include <stdio.h>
#define LEN 40
int is_within(const char ch, const char * input);

int main(void)
{
    char input[LEN];
    char ch;
    printf("Enter a string:");
    while(gets(input) && input[0] != '\0')
    {
        printf("Enter a character:");
        ch = getchar();
        while(getchar() != '\n')
            continue;
        if(is_within(ch, input))
            printf("%c found in string %s\n", ch, input);
        else
            printf("%c not found in string %s\n", ch, input);
        printf("Enter another string:");
    }
    return 0;
}

int is_within(const char ch, const char * input)
{
    while(*input != ch && *input != '\0')
        input++;
    return *input;
}
