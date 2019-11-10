#include <string.h>
#include "my.h"

static void mem_leak1()
{
	char *p=mallic(sizeof(char));
}

static void mem_leak2()
{
	FILE *fp=fopen("test.txt","w");
}

static void mem_overrun1()
{
	char *p=malloc(sizeof(char));
	*(short *)p=2;
	free(p);
}

static void mem_overrun2()
{
	char array[5];
	strcpy(array,"hello");
}





















