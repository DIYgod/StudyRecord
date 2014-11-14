#include <stdio.h>
#define SIZE 26
int main(void)
{
    char letter[SIZE];
    int index;

    for(index = 0; index < SIZE; index ++)
        letter[index] = 'a' + index;
    for(index = 0; index < SIZE; index ++)
        printf("%c", letter[index]);
        printf("\n");

    return 0;
}
