#include "mylib.h"
#include "stdio.h"
#define UNUMBER 5

int main()
{
	int a[UNUMBER];
	urand(a,UNUMBER);
	show(a,UNUMBER);
	printf("max=%d\n",max(a,UNUMBER));
	printf("sum=%d\n",sum(a,UNUMBER));
	return 0;
}
