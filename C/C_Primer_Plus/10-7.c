#include <stdio.h>
#define SIZE1 7
#define SIZE2 3

void copy_arr(const int ar1[], int ar2[], int size);
void put(const int ar[], int size);

int main(void)
{
    int source[SIZE1] = {1, 2, 3, 4, 5, 6, 7};
    int target1[SIZE2];
    copy_arr(source + 2, target1, SIZE2);
    put(source, SIZE1);
    put(target1, SIZE2);

    return 0;
}

void copy_arr(const int ar1[], int ar2[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        ar2[i] = ar1[i];
}

void put(const int ar[], int size)
{
    int i;
    for(i = 0; i <size; i++)
        printf("%d ", *(ar + i));
    printf("\n");
}
