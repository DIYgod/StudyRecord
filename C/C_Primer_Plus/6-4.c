 #include <stdio.h>

 int main(void)
 {
     int space, up, down, line, max;
     char letter;

     printf("Please enter a capital letter:");
     scanf("%c", &letter);
     max = letter - 'A' + 1;

     for (line =1; line <= max; line++)
     {
         for (space = 1; space <= max - line; space++)
            printf(" ");
         for (up = 1; up <= line; up++)
            printf("%c", 'A' + up - 1);
         for (down = 1; down <= line - 1; down++)
            printf("%c", 'A' + line - down - 1);
         printf("\n");
     }

     return 0;
 }
