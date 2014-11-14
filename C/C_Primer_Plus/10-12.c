#include <stdio.h>
#define SIZE1 3
#define SIZE2 5

void store(double ar[], int n);
void show(double ar[][SIZE2], int n);

int main(void)
{
    int i;
    double ar[SIZE1][SIZE2];

    for(i = 0; i < SIZE1; i++)
    {
        printf("Enter 5 numbers for row %d\n", i + 1);
        store(ar[i], SIZE2);
    }

    show(ar, SIZE1);

    return 0;
}

void store(double ar[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        scanf("%lf", &ar[i]);
}

void show(double ar[][SIZE2], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < SIZE2; j++)
        printf("%.1f ", ar[i][j]);
        printf("\n");
    }

}
