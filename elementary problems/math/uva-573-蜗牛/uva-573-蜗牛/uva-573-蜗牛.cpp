// uva-573-蜗牛.cpp : 定义控制台应用程序的入口点。
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
	double H,U,D,F;
	double fatigue_down = 0;
	int k = 1;
	double sum = 0;
	while(scanf("%lf%lf%lf%lf",&H,&U,&D,&F)&&H)
	{
		fatigue_down = U*F/100;
		sum = 0;
		k = 1;
		while(1)
		{
			double temp = U-(k-1)*fatigue_down;
			if(temp>0)
				sum+=temp;
			if(sum>H)
			{
				printf("success on day %d\n",k);
				break;
			}
			sum-=D;
			if(sum<0)
			{
				printf("failure on day %d\n",k);
				break;
			}
			k++;
		}
	}
	return 0;
}

