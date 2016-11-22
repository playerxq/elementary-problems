// uva-10499-land of justice.cpp : 定义控制台应用程序的入口点。
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
	double n;
	while (scanf("%lf",&n)&& n>=0)
	{
		if (n<=1) printf("0%%\n");
		else printf("%.0lf%%\n",25*n);
		//printf("%%");
	}
	return 0;
}

