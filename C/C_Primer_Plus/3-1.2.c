#include <stdio.h>
int main(void)
{
    float a = 1e38;
    float b;
    b = a * 10;
    printf("a = %f, b = %f",a, b);

    return 0;
}
