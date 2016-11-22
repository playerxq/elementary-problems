// uva-11044-search for nessy.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int row,column;
		scanf("%d%d",&row,&column);
		row-=2;
		column-=2;
		int x = floor(((double)row/3.0)+0.5);
		int y = floor(((double)column/3.0)+0.5);
		if(3*x<row) x++;
		if(3*y<column) y++;
		printf("%d\n",x*y);
	}
	return 0;
}

