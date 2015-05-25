#include <stdio.h>
double min(double count1, double count2);

int main(void)
{
    double count1, count2;
    scanf("%lf %lf", &count1, &count2);
    printf("%f", min(count1, count2));
    return 0;
}

double min(double count1, double count2)
{
    return count1 > count2 ? count2 : count1;
}
