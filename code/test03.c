#include "my.h"
 
 int main()
 {
 	int pid,s;
 	if((pid=fork())<0)
 	{
 		printf("failed to fork\n");
 		return -1;
 		
 	}
 	else if(pid==0)
 	{
 		printf("%d:child is running\n",getpid());
 		printf("%d:child is exit now!\n",getpid());		
 		exit(120);
 	}
 	else
 	{
 		printf("%d:parent is waiting zombie now\n",getpid());
 		while((pid=wait(&s))!=-1)
 		{
 			if(WIFEXITED(s))
 			{
 				printf("child %d is exiting normally exit code=%d\n",pid,WEXITSTATUS(s));
 			}
 			else if(WIFSIGNALED(s))
 			{
 				printf("child %d exit by signal no =%d\n ",pid,WTERMSIG(s));
 			}
 			else
 			{
 				printf("Not know!\n");
 			}
 		}
 		
 	}
 
 	exit(0);
 }
 
 
 
 
 
 
 
 
 
 
 
 
