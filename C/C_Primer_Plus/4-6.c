#include <stdio.h>
#include <float.h>
int main(void)
{
    double a = 1.0 / 3.0;
    float b = 1.0/3.0;

    printf("%.4f %.12f %.16f\n", a, a, a);
    printf("%.4f %.12f %.16f\n", b, b, b);
    printf("FLT_DIG = %d, DBL_DIG = %d", FLT_DIG, DBL_DIG);

    return 0;
}
