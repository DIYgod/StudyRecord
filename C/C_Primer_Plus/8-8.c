#include <stdio.h>

float intfloat(void);

int main(void)
{
    float count1, count2, result;
    char type, operat;

    printf("Enter the operation of your choice:\n");
    printf("a. add               s. subtract\n");
    printf("m. multiply          d. divide\n");
    printf("q. quit\n");
    while((type = getchar()) != 'q')
    {
        while(getchar() != '\n');

        if(type != 'a' && type != 's' && type != 'm' && type != 'd')
        {
            printf("Wrong input!\n");
            continue;
        }

        printf("Enter frist number:");
        count1 = intfloat();
        printf("Enter second number:");
        while((count2 = intfloat()) == 0)
        {
            printf("Enter a number other than 0:");
            count2 = intfloat();
        }

        switch(type)
        {
        case 'a':
            operat = '+';
            result = count1 + count2;
            break;
        case 's':
            operat = '-';
            result = count1 - count2;
            break;
        case 'm':
            operat = '*';
            result = count1 * count2;
            break;
        case 'd':
            operat = '/';
            result = count1 / count2;
        }

        printf("%.1f %c %.1f = %.1f\n", count1, operat, count2, result);
        printf("Enter the operation of your choice:\n");
        printf("a. add               s. subtract\n");
        printf("m. multiply          d. divide\n");
        printf("q. quit\n");
        type = getchar();
    }
    printf("Bye.");

    return 0;
}

float intfloat(void)
{
    float input;
    char ch;

    while(scanf("%f", &input) != 1)
    {
        while((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not an number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
    }
    return input;
}
