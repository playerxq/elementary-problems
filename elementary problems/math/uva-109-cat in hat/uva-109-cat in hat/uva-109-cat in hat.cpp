// uva-109-cat in hat.cpp : �������̨Ӧ�ó������ڵ㡣
//
//��ʼ�߶�ΪH  ÿ��ñ����N��è �߶�H��һֻ  �߶�H/(N+1)��Nֻ H/(N+1)^2��N^2ֻ��������������Ϊiʱ���������è��
//��Ŀnum=N^iֻ  ͬʱ�߶�Ϊ1��� H/(N+1)^i==1 H=(N+1)^i ��i��������log(num)*log(N+1)-log(N)*log(H)<eps �õ�N����Լ�����è����߶Ⱥ�
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define eps 1e-9
int main()
{
	int hight,num,left,right,mid,x,y;
	while (scanf("%d%d",&hight,&num),hight+num)
	{
		left=1;  right=10000000;
		while (left<=right)
		{
			mid=(left+right)/2;
			if (fabs(log((double)mid)*log((double)hight)-log((double)mid+1)*log((double)num))<=eps) break;
			if (log((double)mid)*log((double)hight)-log((double)mid+1)*log((double)num)>0) right=mid;
            else left=mid+1;
		}
		x=0; y=hight; left=1;
		while (hight>1)
		{
			hight/=(1+mid); 
			left*=mid;//��ǰ��è��
			x+=left; 
			y+=hight*left;
		 }
		printf("%d %d\n",x-num+1,y);
	}
	return 0;
}

