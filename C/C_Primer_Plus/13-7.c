#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    FILE * f1, * f2;
    int ch1, ch2;
    if(argc < 3)
    {
        fprintf(stderr, "Usage: two filename");
        exit(1);
    }

    if((f1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[1]);
        exit(2);
    }

    if((f2 = fopen(argv[2], "w")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[2]);
        exit(3);
    }

    ch1 = getc(f1);
    ch2 = getc(f2);

    while(ch1 != EOF || ch2 != EOF)
    {
        while(ch1 != EOF && ch1 != '\n')
        {
            putchar(ch1);
            ch1 = getc(f1);
        }
        if(ch1 != EOF)
        {
            putchar(ch1);
            ch1 = getc(f1);
        }
        while(ch2 != EOF)
        {
            putchar(ch2);
            ch2 = getc(f2);
        }
        if(ch2 != EOF)
        {
            putchar(ch2);
            ch2 = getc(f2);
        }
    }

    if (fclose(f1) != 0)
printf("Could not close file %s\n", argv[1]);
if (fclose(f2) != 0)
printf("Could not close file %s\n", argv[2]);
return 0;
}
