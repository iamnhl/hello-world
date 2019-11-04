#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int global1=0;
int global2=0;

int main()
{
	pid_t result;
	//int i = 10;
	//static k = 20;
	result=fork();
	if(result==-1)
	{
		perror("创建子进程失败！\n");
		return 0;
	}
	else if(result==0)
	{
		printf("返回值是%d,说明这是子进程！\n",result);
		printf("此进程的进程号（PID）是:%d\n",getpid());
		printf("此进程的父进程号（PPID）是:%d\n",getppid());
	}
	else
	{
		sleep(2);
		printf("返回值是%d,说明这是父进程！\n",result);
		printf("此进程的进程号（PID）是:%d\n",getpid());
		printf("此进程的父进程号（PPID）是:%d\n",getppid());
		//newret=system("ping www.lupaworld.com");
	}
	
	return 0;
}


















