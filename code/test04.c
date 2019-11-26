#include "my.h"
int count=0;
int main()
{
	pid_t p1,p2,p3;
	int r1,r2,r3,s1,s2,s3;
	printf("parent fork first time\n");
	p1=fork();
	if(p1<0)
	{
		perror("fork failed.\n");
		return -1;
	}
	else if(p1==0)
	{
		count +=1;
		printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
		exit(1);
	}
	else
	{
		printf("parent fork second time\n");
		p2=fork();
		if(p2<0)
		{
			perror("fork failed.\n");
			return -1;
		}
		else if(p2==0)
		{
			count +=1;
			printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
			exit(2);
		}
		else
		{	
			printf("parent fork third time\n");
			p3=fork();
			if(p3<0)
			{
				perror("fork failed.\n");
				return -1;
			}
			else if(p3==0)
			{
				count +=1;
				printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
				exit(3);
			}
			else
			{
				printf("parent waiting\n");
				r1=wait(&s1);
				r2=wait(&s2);
				r3=wait(&s3);
				
				printf("r1=%d,s1=%d,r2=%d,s2=%d,r3=%d,s3=%d\n",
					r1,WEXITSTATUS(s1),r2,WEXITSTATUS(s2),r3,WEXITSTATUS(s3));		
							
				printf("parent pid=%d,count=%d\n",getpid(),count);
				exit(0);
			}
		}	
	}
	
}
