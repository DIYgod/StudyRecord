#include <stdio.h>

void copy_arr(double ar1[], double ar2[], int size);
void put(double ar[], int size);

int main(void)
{
    double source[2][3] = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}};
    double target1[2][3];
    copy_arr(source[0], target1[0], 6);
    put(source[0], 6);
    put(target1[0], 6);

    return 0;
}

void copy_arr(double ar1[], double ar2[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        ar2[i] = ar1[i];
}

void put(double ar[], int size)
{
    int i;
    for(i = 0; i <size; i++)
        printf("%.1f ", *(ar + i));
    printf("\n");
}
