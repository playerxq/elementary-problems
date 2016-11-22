// uva-400-unix ls.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
char file_name[110][100];
int cmp(const void *a,const void *b)  
{  
    return strcmp((char *)a,(char *)b);  
} 
int main()
{
	int N = 0;
	int h_num,l_num;
	while(scanf("%d",&N)!=EOF)
	{
		memset(file_name,0,sizeof(file_name));
		int max_len = -1;
		for(int i = 0;i<N;i++)
		{
			scanf("%s",file_name[i]);
			int temp_len = strlen(file_name[i]);
			if(temp_len>max_len)
				max_len = temp_len;
		}
		qsort(file_name,N,100*sizeof(char),cmp);
		printf("------------------------------------------------------------\n"); 
		h_num=62/(max_len+2);  
        l_num=(N-1)/h_num+1;//上取整
		int len = max_len+2;
		for(int i = 0;i<l_num;i++)
		{
			for(int j = 0;j<h_num;j++)
			{
				if((j)*l_num+i>N-1)
					break;
				printf("%s",file_name[(j)*l_num+i]);
				int num_len=max_len-strlen(file_name[j*l_num+i]);
				for(int k=0;k<num_len;k++)  
                {  
                    printf(" ");  
                }  
                if(j!=h_num-1)  
                    printf("  "); 
			}
			printf("\n"); 
		}
	}
	return 0;
}

