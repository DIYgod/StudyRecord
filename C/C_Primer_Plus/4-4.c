#include <stdio.h>

int main(void)
{
    char name[40];
    float height;

    printf("Enter your height in cm\n");
    scanf("%f", &height);
    printf("Enter your name\n");
    scanf("%s", name);
    printf("%s,you are %.3f metre tall", name, height / 100);

    return 0;
}
