// test-素数-分解.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define max 1000
int is_prime[max];
int factor[max];
int factor_e[max];
int cnt;
void get_prime()
{
	memset(is_prime,1,sizeof(is_prime));
	int n = sqrt((double)max)+1;
	is_prime[1] = 1;
	is_prime[2] = 1;
	for(int i = 2;i<=n;i++)
	{
		if(is_prime[i])
		{
			for(int j = i+i;j<max;j+=i)
				is_prime[j] = 0;
		}
	}
}
void output(int* a, int len)
{
	int num = 0;
	for(int i = 2;i<len;i++)
	{
		if(a[i])
		{
			num++;
			printf("%d ",i);
		}
		if(num%10==0)
			printf("\n");
	}
	printf("\n");
}

void get_n(int n)
{
	memset(factor,0,sizeof(factor));
	memset(factor_e,0,sizeof(factor_e));
	int k = sqrt((double)n)+1;
	int m = 2;
	cnt = 0;
	while(n!=1)
	{
		if(n%m==0)
		{
			int num = 0;
			while(n%m==0)
			{
				num++;
				n = n/m;
			}
			factor[cnt] = m;
			factor_e[cnt++] = num; 
		}
		m++;
	}
}

int search_f(int m)
{
	int left = 0;int right = cnt;
	if(cnt == -1)
	{
		cnt++;
		return cnt;
	}
	while(left<=right)
	{
		int mid = (right+left)/2;
		if(factor[mid]==m)
			return mid;
		else if(factor[mid]<m)
			left = mid+1;
		else
			right = mid-1;
	}
	cnt++;
	return cnt;
}

void get_n_f(int n)
{
	memset(factor,0,sizeof(factor));
	memset(factor_e,0,sizeof(factor_e));
	cnt = -1;
	for (int i=2;i<=n;i++)//对N的阶乘做因数分解  
	{
		int tmp=i;
		int m = 2;
		while(tmp!=1)
		{
			if(tmp%m==0)
			{
				int num = 0;
				while(tmp%m==0)
				{
					num++;
					tmp = tmp/m;
				}
				int index = search_f(m);
				factor[index] = m;
				factor_e[index] += num; 
			}
			m++;
		}
	}
}

void output_x(int cnt)
{
	for(int i = 0;i<cnt;i++)
	{
		if(i<cnt-1)
		{
			printf("%d^%d * ",factor[i],factor_e[i]);
		}
		else 
			printf("%d^%d\n",factor[i],factor_e[i]);
	}
}

int main()
{
	int n = 0;
	get_prime();
	//output(is_prime,max);
	while(scanf("%d",&n)&&n!=0)
	{
		//get_n(n);//计算n的因子分解式
		//output_x(cnt);
		get_n_f(n);//计算n！的因子分解式
		output_x(cnt+1);
	}
	return 0;
}

