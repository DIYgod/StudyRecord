#include <stdio.h>
#define SIZE 5

int imax(int ar[], int size);

int main(void)
{
    int ar[SIZE] = {1, 9, 3, 14, 5};
    int max;
    max = imax(ar, SIZE);
    printf("%d", max);

    return 0;
}

int imax(int ar[], int size)
{
    int max = ar[0], i;
    for(i = 0; i < size - 1; i++)
    {
        if(max < ar[i + 1])
            max = ar[i + 1];
    }
    return max;
}
