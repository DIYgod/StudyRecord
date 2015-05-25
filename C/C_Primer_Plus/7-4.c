#include <stdio.h>
int main(void)
{
    int c1 = 0, c2 = 0;
    char c;

    printf("Please input a string end by #:");
    while((c = getchar()) != '#')
    {
        if(c == '.')
        {
            putchar('!');
            ++c1;
        }
        else if(c == '!')
        {
            putchar('!');
            putchar('!');
            ++c2;
        }
        else
            putchar(c);
    }
    printf("\nThe times of '.' replaced by '!' is %d\n", c1);
    printf("The times of '!' replaced by '!!' is %d\n", c2);

    return 0;
}
