#include <stdio.h>
int main (void)
{
    float kt,number;

    printf("请输入水的夸脱数:");
    scanf("%f", &kt);
    number = 950 / 3.0e-23 * kt;
    printf("水分子个数为:%e",number);

    return 0;
}
