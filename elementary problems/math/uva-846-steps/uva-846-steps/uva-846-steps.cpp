// uva-846-steps.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

int f(int start,int* n,int* max)//���n  ��ʼ����Ϊstart
{
	int sum = start;
	int cnt = 1;
	int k = start+1;//��ߵ�
	while(sum*2+k<=(*n))
	{
		sum+=k;
		k++;
		cnt++;
	}
	(*n)-=2*sum-(k-1);
	(*max) = k-1;
	return 2*(cnt-1)+1;
}

int main()
{
	int from,end;
	int n = 0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&from,&end);
		int step = 0;
		int initial = 1;
		int remain = end-from;
		int max = 0;
		while(remain>0)
		{
			step+=f(initial,&remain,&max);
			initial = max;
			while((remain>0)&&(initial>1)&&(initial>remain))
				initial--;
		}
		printf("%d\n",step);
	}
	return 0;
}

