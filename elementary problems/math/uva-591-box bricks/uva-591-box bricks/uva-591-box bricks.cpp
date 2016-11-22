// uva-591-box bricks.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
int h[55];
int main()
{
	int n = 0;
	int T = 1;
	while(scanf("%d",&n)&&n)
	{
		int sum = 0;
		int count = 0;
		for(int i = 0;i<n;i++)
		{
			scanf("%d",&h[i]);
			sum+=h[i];
		}
		sum/=n;
		for(int i = 0;i<n;i++)
		{
			if(h[i]>sum)
				count+=h[i]-sum;
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",T ++,count);
	}
	return 0;
}

