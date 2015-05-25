#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int p1, p2, i;
	if(p1 = fork())
	{
		lockf(1, 1, 0);
		printf("Father start!\n");
		for(i = 0; i < 500; i++)
		{
			printf("Father %d\n", i);
		}
		lockf(1, 0, 0);
		wait(0);
		exit(0);
	}
	else
	{
		if(p2 = fork())
		{
			lockf(1, 1, 0);
			printf("Son start!\n");
			for(i = 0; i < 500; i++)
			{
				printf("Son %d\n", i);
			}
			lockf(1, 0, 0);
			wait(0);
			exit(0);
		}		
		else
		{
			lockf(1, 1, 0);
			printf("GrandSon start!\n");
			for(i = 0; i < 500; i++)
			{
				printf("GrandSon %d\n", i);
			}
			lockf(1, 0, 0);
			exit(0);
		}
	}
	return 0;	
}
