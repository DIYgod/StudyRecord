#include <stdio.h>
int main (void)
{
    float kt,number;

    printf("������ˮ�Ŀ�����:");
    scanf("%f", &kt);
    number = 950 / 3.0e-23 * kt;
    printf("ˮ���Ӹ���Ϊ:%e",number);

    return 0;
}
