#include "my.h"
int count=0;
int main()
{

	pid_t p1,p2,p3;
	int r1,r2,r3,s1,s2,s3;
	int r_num;
	int pipefd[2];
	char buf[4096];
	memset(buf,0,sizeof(buf));

	if(pipe(pipefd)<0)
	{
		perror("pipe failed.\n");
		return -1;
	}
	else
	{
		printf("parent pipe succeed\n");
	}

	p1=fork();//

	if(p1<0)
	{
		perror("fork failed.\n");
		return -1;
	}
	else if(p1==0)
	{
		count +=1;
		printf("child 1 pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
		
		close(pipefd[0]);//
		if(write(pipefd[1],"abcdefghij",10)!=-1)
		{
			printf("child 1 write ok\n");
		}
		close(pipefd[1]);//
	

		exit(1);
	}
	else
	{
		p2=fork();//

		if(p2<0)
		{
			perror("fork failed.\n");
			return -1;
		}
		else if(p2==0)
		{
			sleep(1);
			count +=1;
			
			printf("child 2 pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
			
			close(pipefd[1]);//
			if((r_num=read(pipefd[0],buf,100))>0)
			{
				printf("child 2 read from pipe:%s,total=%d\n",buf,r_num);
			}			
			close(pipefd[0]);//
			if(write(pipefd[1],"abcdefghij",10)!=-1)
			{
				printf("child 2 write ok\n");
			}
			close(pipefd[1]);//
			
			exit(2);
		}
		else
		{
			p3=fork();//

			if(p3<0)
			{
				perror("fork failed.\n");
				return -1;
			}
			else if(p3==0)
			{
				sleep(2);
				count +=1;
				printf("child 3 pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
				
				close(pipefd[1]);//
				if((r_num=read(pipefd[0],buf,100))>0)
				{
					printf("child 3 read from pipe:%s,total=%d\n",buf,r_num);
				}
				close(pipefd[0]);//
				
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
