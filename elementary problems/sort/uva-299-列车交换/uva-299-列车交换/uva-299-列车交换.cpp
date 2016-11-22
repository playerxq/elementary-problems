// uva-299-列车交换.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
int s[100];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int L;
		scanf("%d",&L);
		memset(s,0,sizeof(s));
		for(int i = 0;i<L;i++)
		{
			scanf("%d",&s[i]);
		}
		int count = 0;
		for(int i = L-1;i>=0;i--)
		{
			for(int j = 0;j<i;j++)
			{
				if(s[j]>s[j+1])
				{
					int temp = s[j+1];
					s[j+1] = s[j];
					s[j] = temp;
					count++;
				}
			}
		}
		printf("Optimal train swapping takes %d swaps.\n",count);
	}
	return 0;
}

