#include <stdio.h>
#include <math.h>

int main(void)
{
    int index, num[8], square[8];

    printf("Please input 8 numbers:");
    for(index = 0; index < 8; index++)
    {
        scanf("%d", &num[index]);
        square[index] = pow(2, num[index]);
    }

    index = 0;
    do
    {
        printf("%4d", square[index]);
        index++;
    }while(index < 8);

    return 0;
}
