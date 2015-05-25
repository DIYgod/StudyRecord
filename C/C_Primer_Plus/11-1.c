#include <stdio.h>
#define N 11
char * get(char * input, int n);

int main(void)
{
    char input[N];
    char * chk;

    chk = get(input, N);
    puts(chk);

    return 0;
}

char * get(char * input, int n)
{
    int i;
    for(i = 0; i < n - 1; i++)
    {
        input[i] = getchar();
        if(input[i] == EOF)
            break;
    }
    input[i] = '\0';
    return input;
}
