// uva-109-cat in hat.cpp : 定义控制台应用程序的入口点。
//
//开始高度为H  每个帽子有N个猫 高度H的一只  高度H/(N+1)的N只 H/(N+1)^2的N^2只。。。迭代层数为i时，最后工作的猫的
//数目num=N^i只  同时高度为1因此 H/(N+1)^i==1 H=(N+1)^i 若i存在则有log(num)*log(N+1)-log(N)*log(H)<eps 得到N后可以计算总猫数与高度和
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
			left*=mid;//当前层猫数
			x+=left; 
			y+=hight*left;
		 }
		printf("%d %d\n",x-num+1,y);
	}
	return 0;
}

