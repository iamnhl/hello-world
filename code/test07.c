#include "my.h"

int main()
{
	FILE *fp;
	pid_t pid1,pid2;
	if((fp=fopen("test07.txt","a+"))==NULL)
	{
		printf("failed to fopen\n");
	}
	
	if( ( (pid1=fork()) && (pid2=fork() )<0) )
	{
		perror("failed to fork");
		exit(1);
	}
	else if(pid1==0)
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
		exit(0);
	}
	else if(pid2==0)
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
		exit(0);
	}
	else
	{
		char buffer[1024];
		sleep(2);
		
		fseek(fp,0,SEEK_SET);
		fread(buffer,sizeof(char),1024,fp);
		printf("文件内容：\n");
		printf("%s\n",buffer);
	}
	fclose(fp);
	exit(0);
}

