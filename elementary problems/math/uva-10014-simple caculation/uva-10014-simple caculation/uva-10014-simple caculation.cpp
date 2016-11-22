// uva-10014-simple caculation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define max 4000
double c[max];
double s[max];
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		memset(c,0,sizeof(c));
		int n = 0;
		double a0,an1;
		scanf("%d",&n);
		scanf("%lf",&a0);
		scanf("%lf",&an1);
		for(int i = 1;i<=n;i++)
		{
			scanf("%lf",&c[i]);
		}
		s[1] = c[1];
		s[2] = c[1] + c[2];
		for(int k = 2;k<=n;k++)
			s[k] = s[k-1] + c[k];
		double sum = 0;
		for(int m = 1;m<=n;m++)
			sum+=s[m];
		printf("%.2lf\n",(n*a0+an1-2*sum)/(n+1));
		if (N) printf("\n");
	}
	return 0;
}

