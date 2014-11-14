#include <stdio.h>

int main(void)
{
    int index, number[8];

    printf("Please input 8 numbers:");
    for(index = 0; index < 8; index++)
        scanf("%d", &number[index]);
    for(index = 7; index >= 0; index--)
        printf("%d", number[index]);

    return 0;
}
