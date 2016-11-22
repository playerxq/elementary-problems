// uva-10387-台球.cpp : 定义控制台应用程序的入口点。
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
const double pi = atan(1.0)*4;
int main()
{
	int a,b,s,m,n;
	while(scanf("%d%d%d%d%d",&a,&b,&s,&m,&n))
	{
		if(a==0&&b==0&&s==0&&m==0&&n==0)
			break;
		double v = 0;
		double angle = 0;
		double v_h = 0;
		double v_v = 0;
		//s*v_h = m*a;
		//s*v_v = n*b;
		v_h = (double)m*(double)a/(double)s;
		v_v = (double)n*(double)b/(double)s;
		v = sqrt(v_h*v_h+v_v*v_v);
		angle = atan(v_v/v_h)*180/pi;
		printf("%.2lf %.2lf\n",angle,v);
	}
	return 0;
}

