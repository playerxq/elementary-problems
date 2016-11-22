// uva-10474-大理石.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
int s[15000];
int cmp(const void* num1, const void* num2)
{
	int a = *(int*)num1;
	int b = *(int*)num2;
	return a-b;
}
int main()
{
	int n,q;
	int case_num = 0;
	int guess = 0;
	while(scanf("%d%d",&n,&q)==2)
	{
		if(n==0&&q==0)
			break;
		case_num++;
		memset(s,0,sizeof(s));
		for(int i = 0;i<n;i++)
			scanf("%d",&s[i]);
		qsort(s,n,sizeof(int),cmp);
		printf("CASE# %d:\n",case_num);
		int pos = 0;
		for(int j = 0;j<q;j++)
		{
			scanf("%d",&guess);
			int k = 0;
			for(k = 0;k<n;k++)
			{
				if(s[k]==guess)
					break;
			}
			pos = k+1;
			if(k<n)
				printf("%d found at %d\n",guess,pos);
			else
				printf("%d not found\n",guess);
		}
	}
	return 0;
}

