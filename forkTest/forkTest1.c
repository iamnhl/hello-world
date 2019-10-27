#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

char buf[]={"write to stdout\n"};
int main()
{
	pid_t id;
	if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
	{
		perror("cant not write");
		
	}
	printf("printf\n");
	id=fork();
	if(id<0)
	{
		perror("fork error");
	}
	return 0;
}




