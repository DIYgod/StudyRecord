#include <stdio.h>
int main(void)
{
    int i, up, low;

    printf("Please input the number of upper limit:");
    scanf("%d", &up);
    printf("Please input the number of lower limit:");
    scanf("%d", &low);

    printf("number square cube\n");
    for (i = low; i <= up; i++)
        printf("%3d %7d %5d\n", i, i * i, i * i * i);

    return 0;
}
