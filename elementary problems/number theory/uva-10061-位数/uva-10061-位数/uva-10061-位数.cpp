#include "stdafx.h"
#include<stdio.h>
#include<math.h>
int main()
{
	int N,B,i,j,n,pos,a[1000],b[1000],c[1000],num,flag,sum;
	double s;
	while (scanf("%d%d",&N,&B)!=EOF)
	{
		s=0;//����λ��
		for (i=1;i<=N;i++)
			s=s+log((double)i);
		s=s/log((double)B)+1e-10;//��������~~~~(>_<)~~~~ 
		pos=s;
  
		for (i=1;i<=B;i++)
		{a[i]=0;b[i]=0;}
  
		for (i=2;i<=N;i++)//��N�Ľ׳��������ֽ�  ֻ��Ҫ����b���ڵ�����  b���ϵ�������˲����ܳ��ֽ�βΪ0 ������b
		{
			n=i;
			for (j=2;j<=sqrt((double)n)+1&&j<=B;j++)//b����Ҳ������  Ҳ��n������
				while (n%j==0) {if (j<=B) ++a[j]; n=n/j;}
			if ((n>1)&&(n<=B)) ++a[n];
		}
  
		n=B;//ͬ���b���ӷֽ�
		for (j=2;j<=sqrt((double)n)+1;j++)
			while (n%j==0) {++b[j]; n=n/j;}
		if (n!=1) ++b[n];
  
		sum=0;
		for (i=2;i<=B;i++)
			if (b[i]>0) {++sum;c[sum]=i;}//����b����b������
  
		flag=1; num=0;
		while (flag)
		{
			for (i=1;i<=sum;i++)//��b������  ����n!�п����ҵ������������Ϊb  ���õ�һ��0
			{
				a[c[i]]=a[c[i]]-b[c[i]];//n!��������  ��Ϊb������ ˵�����Լ���b�����ӷֽ�ʽ��
				if (a[c[i]]<0) {flag=0;break;}//��������� break��
			}
			if (flag) ++num;//�õ�һ�����  ���õ�һ��0
		}
		printf("%d %d\n",num,pos+1);
	}
	return 0;
} 