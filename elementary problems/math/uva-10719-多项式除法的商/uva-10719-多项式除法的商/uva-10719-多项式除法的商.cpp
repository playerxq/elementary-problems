// uva-10719-多项式除法的商.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define max 25000
int a[max];
char s[max];
int q[max];
int r;
int main()
{
	int k = 0;
	char temp;
	int i = 0;
	while(scanf("%d",&k)!=EOF)
	{
		memset(a,0,sizeof(a));
		memset(q,0,sizeof(q));
		i = 0;
		getchar();
		while(1)
		{
			scanf("%d%c",&a[i++],&temp);
			if(temp=='\n')
				break;
		}
		int j = 0;
		int ans = 0;
		int index = 0;
		while(j<i-1)
		{
			ans = ans*k+a[j++];
			q[index++] = ans;
		}
		r = ans*k + a[j];
		printf("q(x): ");
		for(int l = 0;l<index;l++)
		{
			printf("%d",q[l]);
			if(l<index-1)
				printf(" ");
			else
				printf("\n");
		}
		printf("r = %d\n",r);
		printf("\n");
	}
	return 0;
}

