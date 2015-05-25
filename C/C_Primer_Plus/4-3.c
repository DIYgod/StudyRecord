#include <stdio.h>

int main(void)
{
    float number;

    printf("输入一个浮点数\n");
    scanf("%f", &number);
    printf("The input is %.1f or %.1e\n", number, number);
    printf("The input is %+.3f or %.3E", number, number);

    return 0;
}
