#include "stdafx.h"
#include<stdio.h>
#include<math.h>
int main()
{
	int N,B,i,j,n,pos,a[1000],b[1000],c[1000],num,flag,sum;
	double s;
	while (scanf("%d%d",&N,&B)!=EOF)
	{
		s=0;//计算位数
		for (i=1;i<=N;i++)
			s=s+log((double)i);
		s=s/log((double)B)+1e-10;//精度问题~~~~(>_<)~~~~ 
		pos=s;
  
		for (i=1;i<=B;i++)
		{a[i]=0;b[i]=0;}
  
		for (i=2;i<=N;i++)//对N的阶乘做因数分解  只需要考虑b以内的素数  b以上的素数相乘不可能出现结尾为0 即整除b
		{
			n=i;
			for (j=2;j<=sqrt((double)n)+1&&j<=B;j++)//b可能也是素数  也是n的因子
				while (n%j==0) {if (j<=B) ++a[j]; n=n/j;}
			if ((n>1)&&(n<=B)) ++a[n];
		}
  
		n=B;//同理对b因子分解
		for (j=2;j<=sqrt((double)n)+1;j++)
			while (n%j==0) {++b[j]; n=n/j;}
		if (n!=1) ++b[n];
  
		sum=0;
		for (i=2;i<=B;i++)
			if (b[i]>0) {++sum;c[sum]=i;}//保存b以内b的因子
  
		flag=1; num=0;
		while (flag)
		{
			for (i=1;i<=sum;i++)//对b的因子  看看n!中可以找到多少因子组合为b  即得到一个0
			{
				a[c[i]]=a[c[i]]-b[c[i]];//n!的因子中  若为b的因子 说明可以加入b的因子分解式中
				if (a[c[i]]<0) {flag=0;break;}//不够组合了 break掉
			}
			if (flag) ++num;//得到一轮组合  即得到一个0
		}
		printf("%d %d\n",num,pos+1);
	}
	return 0;
} 