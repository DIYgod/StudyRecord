#include <stdio.h>

void copy(int rows, int cols, double ar1[rows][cols], double ar2[rows][cols]);
void show(int rows, int cols, double ar[rows][cols]);

int main(void)
{
    int i, j, rows = 3, cols = 5;
    double ar1[rows][cols], ar2[rows][cols];

    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
        ar1[i][j] = i + j;

    copy(rows, cols, ar1, ar2);
    show(rows, cols, ar1);
    printf("\n");
    show(rows, cols, ar2);

    return 0;
}

void copy(int rows, int cols, double ar1[rows][cols], double ar2[rows][cols])
{
    int i, j;
    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
        ar2[i][j] = ar1[i][j];
}

void show(int rows, int cols, double ar[rows][cols])
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
            printf("%f ", ar[i][j]);
        printf("\n");
    }
}
