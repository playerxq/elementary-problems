// uva-375-isoscele trangle.cpp : 定义控制台应用程序的入口点。
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
const double pi = atan(1.0) * 4;
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		double B,H,h,r;
		double R = 0;
		scanf("%lf%lf",&B,&H);
		R=sqrt(H*H+B*B/4);
		R =B*H/(2*R+B);
		h=H;  r=R;
		while (r>=0.000001)
		{
			h=h-2*r;
			r=R*h/H;//按比例
		}
		printf("%13.6lf\n",(H-h)*pi);
		if (N) printf("\n");
	}
	return 0;
}

