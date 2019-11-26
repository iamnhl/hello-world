#include "my.h"
int main()
{
	int count=0;
	pid_t r;
	int r_num;
	int pipefd[2];
	char buf[4096];
	memset(buf,0,sizeof(buf));
	if(pipe(pipefd)<0)
	{
		perror("pipe failed.\n");
		return -1;
	}
	r=fork();
	if(r<0)
	{
		perror("fork failed.\n");
		return -1;
	}
	else if(r==0)
	{
	close(pipefd[0]);		
		while(write(pipefd[1],"0",1)>0)
		{
			printf("%d\n",count);
			count++;	
		}
		close(pipefd[1]);
		
		exit(0);
	}
	else     
	{
		wait(NULL);
		close(pipefd[1]);
		if((r_num=read(pipefd[0],buf,4096))>0)
		{
			printf("child read from pipe:%s,total=%d\n",buf,r_num);		
		}
		close(pipefd[0]);
		
		return 0;
	}
	
}
















