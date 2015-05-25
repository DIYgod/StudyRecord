#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    FILE *in, *out;
    char ch;

    if(argc != 3)
    {
        fprintf(stderr, "Usage: %s sourcefile targetfile\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((in = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if((out = fopen(argv[2], "wb")) == NULL)
    {
        fprintf(stderr, "I couldn't open and creat the file \"%s\"\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while((ch = getc(in)) != EOF)
        putc(ch, out);

    if(fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
}
