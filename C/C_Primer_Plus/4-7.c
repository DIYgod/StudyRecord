#include <stdio.h>

int main(void)
{
    float yl, jl;

    printf("��������ʻ��Ӣ����:");
    scanf("%f", &yl);
    printf("�������͵ļ�����:");
    scanf("%f", &jl);
    printf("%.1f yl per jl\n", yl / jl);

    const float l = 3.785;
    const float km = 1.609;

    printf("%.1f l per 100km", yl / jl * l / km * 100);
    return 0;
}
