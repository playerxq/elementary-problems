#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void *a,const void *b)
{return *(int*)a-*(int*)b;}

void main()
{
	char s[300];
	 int alpha[27]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0},i,j,n,l,number,sum,t;
	 int a[100001];
	 scanf("%d",&t);
	 while (t--)
	 {
		scanf("%d\n",&n);
		for (j=0;j<n;j++)
		{
			scanf("%s",&s);
			number=0;
			l=strlen(s);
			for (i=0;i<l;i++)
			{
				if ((s[i]>='A')&&(s[i]<='Z')) number=number*10+alpha[s[i]-'A'];
				if ((s[i]>='0')&&(s[i]<='9')) number=number*10+s[i]-'0';
			}
			a[j]=number;
		}
		qsort(a,n,sizeof(int),comp);
		i=0;  sum=0;
		while (i<n-1)
		{
			j=i;
			while ((j<n-1)&&(a[j]==a[j+1])) j++;
			if (j>i) {printf("%03d-%04d %d\n",a[i]/10000,a[i]%10000,j-i+1);++sum;}
			i=j+1;
		}
		if (sum==0) printf("No duplicates.\n");
		if (t) printf("\n");
	 }
}