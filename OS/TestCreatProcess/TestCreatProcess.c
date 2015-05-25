#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int p1, p2, i;
	if(p1 = fork())
	{
		printf("Father start!\n");
		for(i = 0; i < 500; i++)
		{
			printf("Father %d\n", i);
		}
		wait(0);
		exit(0);
	}
	else
	{
		if(p2 = fork())
		{
			printf("Son start!\n");
			for(i = 0; i < 500; i++)
			{
				printf("Son %d\n", i);
			}
			wait(0);
			exit(0);
		}		
		else
		{
			printf("GrandSon start!\n");
			for(i = 0; i < 500; i++)
			{
				printf("GrandSon %d\n", i);
			}
			exit(0);
		}
	}
	return 0;	
}
