#include <stdio.h>

int main(void)
{
    char fname[40];

    printf("Enter your first name\n");
    scanf("%s", fname);
    printf("\"%s\"\n", fname);
    printf("\"%20s\"\n", fname);
    printf("\"%-20s\"\n", fname);
    printf("   %s\n", fname);

    return 0;
}
