// uva-10025-k problem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define max 70000
long a[max];
int main()
{
	int n;
	int num = 0;
	long k = 0;
	int cnt = 2;
	a[1] = 1;
	while(1)
	{
		a[cnt] = a[cnt-1]+cnt;
		if(a[cnt]>1000000000) break;
		cnt++;
	}
	scanf("%d",&n);
	while(n--)
	{
		long x = 1;
		long sum = 0;
		scanf("%ld",&k);
		if(k<0)
			k = -k;
		while(x<cnt)
		{
			if((a[x]>=k)&&(a[x]-k)%2==0)
				break;
			x++;
		}
		if(num)
			printf("\n");
		printf("%ld\n",x);
		num++;
	}
	return 0;
}

