// uva-152-一堆树.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;
///
#define INF 0xffffff7
#define maxn 10000 
///
struct point{
	int x, y, z;
};
point r[maxn];

int main()
{
	///
	int i, j;
	int n(0), x, y, z;
	while (scanf("%d%d%d", &x, &y, &z) == 3 && (x || y || z))
	{
		n++;
		r[n].x = x;
		r[n].y = y;
		r[n].z = z;
	}
	int distance[17] = {0};
	for (i = 1; i <= n; i++)
	{
		int dis(INF);
		for (j = 1; j <= n; j++)
		{
			if (i == j)
				continue;
			int s((int)sqrt((r[i].x-r[j].x)*(r[i].x-r[j].x)+(r[i].y-r[j].y)*(r[i].y-r[j].y)+(r[i].z-r[j].z)*(r[i].z-r[j].z)));
			if (dis > s)
				dis = s;
		}
		if (dis <= 9)
			distance[dis]++;
	}
	
	for(i = 0; i <= 9; i++)
        printf("%4d", distance[i]);
    printf("\n");

    ///
    return 0;
	
}

