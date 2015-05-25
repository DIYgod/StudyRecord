#include <stdio.h>
#define SIZE 20

int main(void)
{
    char i[255];
    int index;

    printf("Please input 20 characters:");
    for(index = 0; index < SIZE; index++)
        scanf("%c", &i[index]);

    for(index = SIZE - 1; index >= 0;index--)
        printf("%c", i[index]);

    return 0;
}
