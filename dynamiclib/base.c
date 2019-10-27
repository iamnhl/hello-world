#include<stdlib.h>
#include<time.h>

void urand(int *a,int n)
{
	int i;
	srand ((int)time(0));
	for(i=0;i<n;i++)
	{
		a[i]=1+(int)(100.0*rand()/(RAND_MAX+1.0));
	}	
}

int max(int* a,int n) 
{
	int m,i;
	m=a[0];
	for(i=0;i<n;i++)
	{
		if(m<a[i])
		{
			m=a[i];
		}
	}
	return m;
}
int sum(int* a,int n)
{
	int i;
	int s=0;
	for(i=0;i<n;i++)
	{
		s=a[i]+s;
	}
	return n;
}
