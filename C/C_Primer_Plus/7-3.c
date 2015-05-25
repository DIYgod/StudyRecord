#include <stdio.h>

int main(void)
{
    int co = 0, cj = 0, i, sumo = 0, sumj = 0;
    float aveo = 0, avej = 0;

    printf("Please input some digites:");

    while(scanf("%d", &i) == 1 && i != 0)
    {
            if(i % 2)
            {
                cj++;
                sumj += i;
            }
            else
            {
                co++;
                sumo += i;
            }
    }
    aveo = sumo / co;
    avej = sumj / cj;
    printf("o count:%d, average:%.2f\nj count:%d, average:%.2f\n", co, aveo, cj, avej);

    return 0;
}
