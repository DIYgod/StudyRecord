#include <stdio.h>
int main(void)
{
    float age, second;

    printf("请输入您的年龄:__\b\b");
    scanf("%f", &age);
    second = age * 3.156e7;
    printf("您活了%.0f秒", second);

    return 0;
}
