#include <stdio.h>
#define SIZE 5

void copy_arr(double ar1[], double ar2[], int size);
void copy_ptr(double * ar1, double * ar2, int size);
void put(double ar[], int size);

int main(void)
{
    double source[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[SIZE];
    double target2[SIZE];
    copy_arr(source, target1, SIZE);
    copy_ptr(source, target2, SIZE);
    put(source, SIZE);
    put(target1, SIZE);
    put(target2, SIZE);

    return 0;
}

void copy_arr(double ar1[], double ar2[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        ar2[i] = ar1[i];
}

void copy_ptr(double * ar1, double * ar2, int size)
{
    int i;
    for(i = 0; i < size; i++)
        *(ar2 + i) = *(ar1 + i);
}

void put(double ar[], int size)
{
    int i;
    for(i = 0; i <size; i++)
        printf("%.1f ", *(ar + i));
    printf("\n");
}
