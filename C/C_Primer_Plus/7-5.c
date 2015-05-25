#include <stdio.h>

int main(void)
{
    int i, left, co = 0, cj = 0, sumo = 0, sumj = 0;
    float aveo, avej;

    printf("Please input some numbers:");
    while(scanf("%d", &i) == 1 && i != 0)
    {
        left = i % 2;
        switch(left)
        {
        case 0:
            co++;
            sumo += i;
            break;
        case 1:
            cj++;
            sumj += i;
            break;
        }
    }

    aveo = sumo / co;
    avej = sumj / cj;
    printf("o count:%d average:%f\nj count:%d average:%f", co, aveo, cj, avej);

    return 0;
}
