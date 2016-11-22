// uva-10112-myacm triangle.cpp : 定义控制台应用程序的入口点。
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
int a[20][5];
char s[5];
double area(int x0,int y0,int x1,int y1,int x2,int y2)
{
	return fabs((double)(x0*y1+x2*y0+x1*y2-x2*y1-x0*y2-x1*y0))/2.0;
}
int cmp(const void* a, const void* b)
{
	if(a<b)
		return -1;
	else if(a>b)
		return 1;
	return 0;
}
int ok(int i,int j,int k,int h)
{
	double area_a = area(a[i][1],a[i][2],a[j][1],a[j][2],a[k][1],a[k][2]);
	double area_1 = area(a[h][1],a[h][2],a[j][1],a[j][2],a[k][1],a[k][2]);
	double area_2 = area(a[h][1],a[h][2],a[i][1],a[i][2],a[k][1],a[k][2]);
	double area_3 = area(a[h][1],a[h][2],a[i][1],a[i][2],a[j][1],a[j][2]);
	if(fabs((area_1+area_2+area_3)-area_a)<1e-9)
		return 0;
	return 1;
}
int main()
{
	int N;
	while(scanf("%d",&N))
	{
		if(N==0)
			break;
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		char c = 0;
		getchar();
		for(int i = 0;i<N;i++)
		{
			scanf("%c",&c);
			a[i][0] = c - 'A';
			scanf("%d%d",&a[i][1],&a[i][2]);
			getchar();
		}
		double max = 0;
		for(int i = 0;i<N;i++)
		{
			for(int j = i+1;j<N;j++)
			{
				for(int k = j+1;k<N;k++)
				{
					if(area(a[i][1],a[i][2],a[j][1],a[j][2],a[k][1],a[k][2])<1e-9)
					{
						continue;
					}
					int flag = 1;
					for(int h = 0;h<N;h++)
					{
						if(h!=i&&h!=j&&h!=k)
						{
							if(!ok(i,j,k,h))
							{
								flag = 0;
								break;
							}
						}
					}
					if(flag)
					{
						if(max<area(a[i][1],a[i][2],a[j][1],a[j][2],a[k][1],a[k][2]))
						{
								max = area(a[i][1],a[i][2],a[j][1],a[j][2],a[k][1],a[k][2]);
								s[0] = a[i][0]+'A';
								s[1] = a[j][0]+'A';
								s[2] = a[k][0]+'A';
						}
					}
				}
			}
		}
		qsort(s,3,sizeof(char),cmp);
		printf("%c%c%c\n",s[0],s[1],s[2]);
	}
	return 0;
}

