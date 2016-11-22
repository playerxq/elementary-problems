// uva-350-随机数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
bool isVis[10000];  
int data[10000];
int num;
int main()
{
	int Z,M,I,L;
	int k = 1; 
	while(scanf("%d%d%d%d",&Z,&I,&M,&L))
	{
		if(Z==0&&M==0&&I==0&&L==0)
			break;
		memset(isVis, false, sizeof(isVis));  
        isVis[L] = true;  
        num = 1;  
        data[0] = L; 
		while(true) {  
            L = (Z * L + I) % M;  
            if(isVis[L]) break;  //找到一个循环
            isVis[L] = true;  
            data[num++] = L;  
        }
		int i = 0;  
        for(; ; i++) {  
            if(data[i] == L) break;  //找到起始点
        }  
        printf("Case %d: %d\n", k++, num - i);  
	}
	return 0;
}

