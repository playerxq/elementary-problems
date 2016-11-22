// uva-10916-超级计算机.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <algorithm>
using namespace std;
int sqr[21];
int main()
{
	int year;
	sqr[0] = 4;
	for(int i = 1;i<21;i++)
	{
		sqr[i] = 2*sqr[i-1];
	}
	while(1)
	{
		scanf("%d",&year);
		if(year == 0)
			break;
		int dif = (year - 1960)/10;
		double p = sqr[dif];
		for(int k = 1;;k++)
		{
			double t = k;
			p -= log(t)/log(2.0);
			if(p<0.0)
			{  
                printf("%d\n",k-1);  
                break;  
            } 
		}
	}
	return 0;
}

