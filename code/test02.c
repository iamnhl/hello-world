#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char *args[]={"/home/nhl/test/code/test",NULL};
	printf("系统进程号（PID）是：%d\n",getpid());
	if(execve("/home/nhl/test/code/test",args,NULL)<0)
	{
		perror("用execve创建进程出错");
	}
	else
	{
		printf("After calling\n");
	}
	
	return 0;
}
