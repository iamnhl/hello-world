#include "my.h"
#define NUM_THREADS 4
struct info
{
	int no;
	int n;
};
void hello(void *t)
{
	struct timeval tv1,tv2;     
	gettimeofday(&tv1, NULL);
	printf("start time is tv_usec: %ld\n", tv1.tv_usec);
	pthread_t my_tid;
	struct info *y;
	int s=0;
	y=(struct info *)(t);
	for(int i=0;i<=y->n;i++)
	{
		s=s+i;
	}
	my_tid=pthread_self();
	printf("\t thread %d: my tid is %lx, hello world \n",(int)y->no,my_tid);
	printf("\t thread %d sum 1 to %d is %d \n",(int)y->no,y->n,s);
	gettimeofday(&tv2, NULL);
	printf("end time is tv_usec: %ld\n", tv2.tv_usec);
	printf("use:%ld\n",tv2.tv_usec-tv1.tv_usec);
}

int main()
{
	pthread_t tid;
	struct info a[NUM_THREADS];
	int rv,t;
	for(t=0;t<NUM_THREADS;t++)
	{
		a[t].no=t;
		a[t].n=100*(t+1);
		
		rv=pthread_create(&tid,NULL,(void*(*)())hello,(void*)&a[t]);
		if(rv!=0)
		{
			printf("thread create failed\n");
			return -1;
		}
		printf("create thread %lx\n",tid);
	}
	printf("good bye\n");
	pthread_exit(NULL);
}
