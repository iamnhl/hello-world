#include "my.h"
int count=0;
int main()
{
	pid_t p1,p2,p3;
	p1=vfork();
	p2=vfork();
	p3=vfork();
	if(p1<0||p2<0||p3<0)
	{
		perror("fork failed.\n");
		return -1;
	}
	else if(p1==0)
	{
		count +=1;
		printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
		exit(0);
	}
	else if(p2==0)
	{
		count +=1;
		printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
		exit(0);
	}
	else if(p3==0)
	{
		count +=1;
		printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
		exit(0);
	}
	else
	{
		printf("parent sleeping!\n");
		sleep(3);
		count +=1;
		printf("parent pid=%d,count=%d\n",getpid(),count);
		exit(0);
	}
	
}
