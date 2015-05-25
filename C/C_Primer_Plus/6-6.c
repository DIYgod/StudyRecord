#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[40];
    int length, index;

    printf("Please input a word:");
    scanf("%s", word);

    length = strlen(word);
    for (index = 0; index < length; index++)
        printf("%c", word[length - index - 1]);

    return 0;
}
