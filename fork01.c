#include "my.h"


int main()
{
	int count=99;
	pid_t pid;
	pid = fork();
	if(pid<0)
	{
		perror("fork failed\n");
		return -1;
	}
	else if(pid==0)
	{
		//count = count+1;
		printf("子进程child pid=%d,count=%d,&count=%p\n",getpid(),count,&count);
		exit(0);
	}
	else
	{
		printf("父进程 pid=%d,count=%d,&count=%p\n",getpid(),count,&count);
		return 0;
	}
}
