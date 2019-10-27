#include"uhead.h"


struct arg operater(int *a,int n)
{
	struct arg t;
	int i=0;
	t.sum=0;
	t.ave=0.0;
	for(i=0;i<n;i++)
	{
		t.sum=t.sum+a[i];
	}
	t.ave=t.sum/n;
	return t;	
}
