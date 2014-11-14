#include <stdio.h>
int main(void)
{
    float cm, inch;

    printf("请输入您的身高:___cm\b\b\b\b\b");
    scanf("%f", &cm);
    inch = cm / 2.54;
    printf("等价于%f英尺", inch);

    return 0;
}
