#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	printf("Call:pid:%d,ppid:%d\n",getpid(),getppid());
	system("./test");
	printf("After calling\n");
	return 0;
}
