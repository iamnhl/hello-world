#include "my.h"

int main()
{
	FILE *fp;
	pid_t pid;
	char buffer[1024];
	if((fp=fopen("fork.txt","a+"))==NULL)
	{
		printf("failed to fopen\n");
	}
	
	if( (pid=fork())<0 )
	{
		perror("failed to fork");
		exit(1);
	}
	else if(pid==0)
	{
		int i;
		char buf[]="0123456789";
		for(i=0;i<10;i++)
		{
			sleep(0.1);
			printf("父进程%d:写入%d\n",getpid(),i);	
			fprintf(fp, "%d: ",getpid());	
			fputc(buf[i],fp);
			fputc('\n',fp);
		}
		exit(0);
	}
	
	else
	{
		int i;
		char buf[]="0123456789";
		for(i=0;i<10;i++)
		{
			sleep(0.1);
			printf("子进程%d:写入%d\n",getpid(),i);	
			fprintf(fp, "%d: ",getpid());	
			fputc(buf[i],fp);
			fputc('\n',fp);
		}	
	}
	fseek(fp,0,SEEK_SET);
	fread(buffer,sizeof(char),1024,fp);
	printf("fork.txt文件内容：\n");
	printf("%s\n",buffer);
	
	fclose(fp);
	exit(0);
}

