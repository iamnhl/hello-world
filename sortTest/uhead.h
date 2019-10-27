#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <sys/time.h> 

#define UNUMBER 100

struct arg
{
	int sum;
	float ave;
};

void urand(int *,int);
void show(int *,int);
struct arg operater(int *,int);
int cmp(const void *p,const void *q);
void bubbleSort(int * pArr, int cnt);

