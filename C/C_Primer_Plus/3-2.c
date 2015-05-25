#include <stdio.h>
int main(void)
{
    int a;

    printf("请输入ASCII码值:__\b\b");
    scanf("%d", &a);
    printf("相应字符为:%c", a);

    return 0;
}
