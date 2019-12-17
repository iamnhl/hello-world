#include "my.h"

void * thread_fun(void* arg)
{
	printf("thread pid = %d\n",getpid());
}

int main()
{
	pthread_t tidp;
	int error;
	error=pthread_create(&tidp,NULL,thread_fun,NULL);
	if(error!=0)
	{
		printf("pthread create is not created \n");
		return -1;
	}
	printf("pthread create is created pid=%d\n",getpid());
	pthread_join(tidp,NULL);
	return 0;
}
