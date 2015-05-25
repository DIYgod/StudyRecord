#include <stdio.h>
#define TYPE1 17850
#define TYPE2 23900
#define TYPE3 29750
#define TYPE4 14875
#define RATE1 0.15
#define RATE2 0.28

int main(void)
{
    int type, pay, tax;
    printf("Select the type of marriage:\n");
    printf("1)SINGLE\n2)HOST\n3)MARRIED_SHARE\n4)MARRIED_DIVORCE\n5)quit\n");
    while(scanf("%d", &type) == 1 && type != 5)
    {
        switch(type)
        {
        case 1:
            type = TYPE1;
            break;
        case 2:
            type = TYPE2;
            break;
        case 3:
            type = TYPE3;
            break;
        case 4:
            type = TYPE4;
            break;
        default:
            printf("Error!\n");
            continue;
        }
        printf("Please input the pay:");
        scanf("%d", &pay);

        if(pay <= type)
            tax = pay * RATE1;
        else
            tax = (pay - type) * RATE2 + type * RATE1;

        printf("tax:%d\n", tax);
        printf("Please input another type:");
    }
    return 0;
}
