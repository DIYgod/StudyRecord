#include <stdio.h>

int main(void)
{
    float yl, jl;

    printf("请输入行驶的英里数:");
    scanf("%f", &yl);
    printf("消耗汽油的加仑数:");
    scanf("%f", &jl);
    printf("%.1f yl per jl\n", yl / jl);

    const float l = 3.785;
    const float km = 1.609;

    printf("%.1f l per 100km", yl / jl * l / km * 100);
    return 0;
}
