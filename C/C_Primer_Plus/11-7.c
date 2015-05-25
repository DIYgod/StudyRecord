#include <stdio.h>
#define LEN 40
char * string_in(char * input1, const char * input2);

int main(void)
{
    char input1[LEN], input2[LEN];
    char * find;
    printf("Enter the string:");
    while(gets(input1) && input1[0] != '\0')
    {
        printf("Enter the string you want:");
        while(gets(input2) && input2[0] != '\0')
        {
            find = string_in(input1, input2);
            if(find)
                printf("String:%p, find:%p\n", input1, find);
            else
                printf("Not find!\n");
        }
        printf("Enter the string:");
    }
    return 0;
}

#include <string.h>
char * string_in(char * string1, const char * string2)
{
    int find;
    int i = 0, max, len2;
    max = strlen(string1) - strlen(string2) + 1;
    len2 = strlen(string2);
    while(i <= max && (find = strncmp(string1, string2, len2)))
    {
        string1++;
        i++;
    }
    if(find == 0)
        return string1;
    else
        return NULL;
}
