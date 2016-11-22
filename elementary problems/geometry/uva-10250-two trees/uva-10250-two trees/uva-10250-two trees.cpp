// uva-10250-two trees.cpp : 定义控制台应用程序的入口点。
//设向量AB=(x,y) 绕起点逆时针转a角后向量为(xcosa-ysina,xsina+ycosa)此题为90度特殊情况

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
	double x1,x2,y1,y2;
	double x3,y3,x4,y4;
	while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF)
	{
		if(x1==x2 && y1==y2)
			printf("Impossible.\n");
		double cx = (x1+x2)/2;
		double cy = (y1+y2)/2;//起点 
		x1-=cx;
		x2-=cx;
		y1-=cy;
		y2-=cy;//起点为(cx,cy)时的向量
		x3 = -y1;
		y3 = x1;
		x4 = -y2;
		y4 = x2;
		 printf("%lf %lf %lf %lf\n",x3+cx,y3+cy,x4+cx,y4+cy);
	}
	return 0;
}

