#include <stdio.h>
int main(void)
{
    float cm, inch;

    printf("�������������:___cm\b\b\b\b\b");
    scanf("%f", &cm);
    inch = cm / 2.54;
    printf("�ȼ���%fӢ��", inch);

    return 0;
}
