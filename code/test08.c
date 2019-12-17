#include "my.h"

int fun(void *d)
{
	printf("tid=%ld\n",pthread_self());
}

int main()
{
	pthread_t tid;
	int ret;
	ret=pthread_create(&tid,NULL,(void*(*)())fun,NULL);
	pthread_join(tid,NULL);
	sleep(2);
	ret=pthread_create(&tid,NULL,(void*(*)())fun,NULL);
	pthread_join(tid,NULL);
	return 0;
}
