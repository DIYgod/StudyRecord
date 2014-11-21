#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int pid1,pid2; 
int main(void)
{ 
	int fd[2];
	char outpipe[] = "Another";
	char inpipe[20];
	pipe(fd);                       /*创建一个管道*/
	while ((pid1=fork())==-1);
	if(pid1==0)
	{
		lockf(fd[1],1,0);
		write(fd[1],outpipe,sizeof(outpipe)); /*向管道写长为50字节的串*/
    		sleep(2);                 /*自我阻塞2秒*/
    		lockf(fd[1],0,0);
    		exit(0);
  	}
	else
  	{
		while((pid2=fork())==-1);
    		if(pid2==0)
		{ 
			lockf(fd[1],1,0);           /*互斥*/
        		write(fd[1],outpipe,sizeof(outpipe));
        		sleep(2);
        		lockf(fd[1],0,0);
        		exit(0);
     		}
     		else
     		{  
			wait(0);              /*同步*/
         		read(fd[0],inpipe,sizeof(outpipe));   /*从管道中读长为50字节的串*/
         		printf("%s\n",inpipe);
         		wait(0);
         		read(fd[0],inpipe,sizeof(outpipe));
         		printf("%s\n",inpipe);
        		exit(0);
    		}
  	}
	
}
