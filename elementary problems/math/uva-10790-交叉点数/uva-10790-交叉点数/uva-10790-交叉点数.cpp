// uva-10790-�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

int main()
{
	long long a,b;
	long long cnt = 0;
	while(scanf("%lld%lld",&a,&b))
	{
		cnt++;
		if((a==0)&&(b==0))
			break;
		long long sum = 0;
		sum = a*(a-1)*b*(b-1)/4;
		printf("Case %lld: %lld\n",cnt,sum);
	}
	return 0;
}

