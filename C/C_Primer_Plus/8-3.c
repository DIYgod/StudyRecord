#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch, lower = 0, upper = 0;

    while((ch = getchar()) != EOF)
    {
        if(islower(ch))
            lower++;
        else if(isupper(ch))
            upper++;
    }

    printf("lower:%d, upper:%d", lower, upper);

    return 0;
}
