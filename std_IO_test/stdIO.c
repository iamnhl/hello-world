#include "uhead.h"

int CreateFile(char * filename)
{
	int fd = 0;
	fd = open(filename, O_CREAT,S_IRWXG|S_IRWXU);
	if(fd == -1)
	{
		printf("Create error\n");
		return 0;
	}
	printf("文件%s创建成功\n",filename);
	close(fd);
	return 1;
}

int WriteFile(char * filename,char * text)
{
	int fd_write = 0;
	int fd=0;
	int textLength = 0;
	char *buf;
	textLength = strlen(text);
	buf = (char *)malloc(textLength * sizeof(char));
	memset(buf, 0, textLength);
	strcpy(buf, text);
	fd = open(filename,O_RDWR|O_APPEND);
	if(fd == -1)
	{
		printf("Open error!\n");
		return 0;
	}
	fd_write=write(fd,buf,strlen(buf));
	if(fd_write == -1)
	{
		printf("Write error!\n");
		return 0;
	}
	printf("成功写入%d个字符到%s:%s\n",fd_write,filename,buf);
	free(buf);
	close(fd);
	return 1;
}

char* ReadFile(char * filename)
{
	char buf[1024]="";	
	int fd_read=0;
	int fd=-1;
	char *pbuf=buf;
	fd = open(filename,O_RDWR);
	if(fd == -1)
	{
		printf("Open error!\n");
		return NULL;
	}
	fd_read = read(fd,buf,sizeof(buf));
	if(fd_read == -1)
	{
		printf("Read error!\n");
		return NULL;
	}
	printf("成功从%s读取%d个字符:%s\n",filename,fd_read,buf);	
	close(fd);
	return pbuf;
}

struct stat StatFile(char *filename)
{
	int fd_stat=0;
	struct stat buf;
	fd_stat=stat(filename,&buf);
	if(fd_stat==-1)
	{
		printf("Stat error!\n");
		return buf;
	}
	printf("此文件的文件权限为%d！\n",buf.st_mode);
	return buf;
}

int ChmodFile(char *filename,unsigned int mode)
{
	int fd_chmod=0;
	chmod(filename,mode);
	if(fd_chmod==-1)
	{
		printf("Chmod error!\n");
		return 0;
	}
	printf("成功将文件权限修改为：%d！\n",mode);
	return 1;
}






