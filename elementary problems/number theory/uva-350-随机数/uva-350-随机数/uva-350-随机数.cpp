// uva-350-�����.cpp : �������̨Ӧ�ó������ڵ㡣
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
            if(isVis[L]) break;  //�ҵ�һ��ѭ��
            isVis[L] = true;  
            data[num++] = L;  
        }
		int i = 0;  
        for(; ; i++) {  
            if(data[i] == L) break;  //�ҵ���ʼ��
        }  
        printf("Case %d: %d\n", k++, num - i);  
	}
	return 0;
}

