#include "uhead.h"

int main()
{
	int a[UNUMBER];
	struct arg t;
    struct timeval start, end;  

 
	urand(a,UNUMBER);	
	printf("排序前：\n");
	show(a,UNUMBER);
	
	gettimeofday(&start, NULL);	
	qsort(a,UNUMBER,sizeof(a[0]),cmp);
	gettimeofday(&end, NULL); 
	long long t1 = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec); 
    printf("快速排序结果：%lld us\n", t1);	
	show(a,UNUMBER);
	
	gettimeofday(&start, NULL);	
	bubbleSort(a,UNUMBER);
	gettimeofday(&end, NULL); 
	long long t2 = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec); 
    printf("冒泡排序结果：%lld us\n", t2);
	show(a,UNUMBER);
	
	t=operater(a,UNUMBER);
	printf("求和与平均数：\n");	
	printf("sum=%d,ave=%f\n",t.sum,t.ave);
	    
   
//    total_time /= 1000; 
//    printf("total time is %lld ms\n", total_time);
	
	return 0;
}
