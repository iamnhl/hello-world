#include "uhead.h"

void bubbleSort(int * pArr, int cnt)  
{  
    int i,j,tmp;  
    for(i=0;i<cnt;i++)  
    {  
        for(j=i+1;j<cnt;j++)  
        {  
            if(*(pArr+i)>*(pArr+j))  
            {  
                tmp=*(pArr+i);  
                *(pArr+i)=*(pArr+j);  
                *(pArr+j)=tmp;  
            }  
        }  
    }  
}  
