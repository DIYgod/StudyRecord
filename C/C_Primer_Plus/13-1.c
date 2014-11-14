/* count.c -- using standard I/O */
#include <stdio.h>

#include <stdlib.h> // ANSI C exit() prototype
#define MAX 40
int main(void)
{
    int ch;         // place to store each character as read
    char fname[MAX];
    FILE *fp;       // "file pointer"
    long count = 0;
    printf("Enter file's name: ");
    gets(fname);
    if ((fp = fopen(fname, "r")) == NULL)
    {
        printf("Can't open %s\n", fname);
        exit(1);
    }
    while ((ch = getc(fp)) != EOF)
    {
       putc(ch,stdout);  // same as putchar(ch);
       count++;
    }
    fclose(fp);
    printf("File %s has %ld characters\n", fname, count);

    return 0;
}
