#include <stdio.h>
#define SIZE 5

double imax(double ar[], int size);

int main(void)
{
    double ar[SIZE] = {1.8, 9.4, 3.8, 4.2, 5.6};
    double differ;
    differ = imax(ar, SIZE);
    printf("%f", differ);

    return 0;
}

double imax(double ar[], int size)
{
    double max = ar[0], min = ar[0];
    int i;
    double differ;
    for(i = 0; i < size - 1; i++)
    {
        if(max < ar[i + 1])
            max = ar[i +1];
        if(min > ar[i + 1])
            min = ar[i + 1];
    }
    differ = max - min;
    return differ;
}
