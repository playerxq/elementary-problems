// uva-579-clock hands.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

int main()
{
	int H,M;
	double dif;
	while(scanf("%d:%d",&H,&M))
	{
		if(H==0&&M==0)
			break;
		dif = 0;
		double angle_H;
		double angle_M;
		angle_H = H*30.0;
		angle_H += M*1/2.0;
		angle_M = M*6.0;
		if(angle_H<angle_M) swap(angle_H,angle_M);
		dif = angle_H-angle_M;
		if(dif>180)
			dif = 360 - dif;
		printf("%.3lf\n",dif);
	}
	return 0;
}

