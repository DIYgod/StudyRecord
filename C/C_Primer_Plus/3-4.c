#include <stdio.h>
int main(void)
{
    float a;
    printf("输入一个浮点数:");
    scanf("%f", &a);
    printf("The input is %f or %e.", a, a);

    return 0;
}
