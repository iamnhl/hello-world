#include "my.h"

static void callback1()
{
	printf("-----callback1-----\n");
}

static void callback2()
{
	printf("-----callback2-----\n");
}

static void __attribute ((constructor)) before_main()
{
	printf("-----constrtuctor------\n");
}

static void __attribute ((destructor)) after_main()
{
	printf("-----desstrtuctor------\n");
}

int main()
{
	atexit(callback1);
	atexit(callback2);
	FILE *fp;
	char buf[]={"test data from full buffer!"};
	if((fp=fopen("test.dat","w+"))==NULL)
	{
		perror("failed to fopen!\n");
		return -1;
	}
	if(fputs(buf,fp)==EOF)
	{
		perror("failed to fputs!\n");
		return -1;
	}
	printf("printf:data from line buffer");
	//exit(0);
	//_exit(0);
	return 0;
}




























