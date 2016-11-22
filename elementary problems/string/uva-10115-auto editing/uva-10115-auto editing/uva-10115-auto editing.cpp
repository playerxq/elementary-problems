// uva-10115-auto editing.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k,n,m,s,s1,ss,tt,k1;
	char str[10000],yuan[1000][100],ti[1000][100];
	char str1[10000];
	while(scanf("%d",&n)&&n)
	{
		getchar();
		for(i=0;i<n;i++)
		{
			gets(yuan[i]);
			gets(ti[i]);
		}
		gets(str);
		m=strlen(str);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(str[j]==yuan[i][0])
				{
					s=strlen(yuan[i]);
					for(k=0;k<s;k++)
					{
						if(str[j+k]!=yuan[i][k])
							break;
					}
					if(k==s)
					{
						s1=strlen(ti[i]);
						ss=s1-s;
						for(k=0;k<j;k++)
							str1[k]=str[k];
						for(k=j;k<j+s1;k++)
							str1[k]=ti[i][k-j];
						for(;k<m+ss;k++)
							str1[k]=str[k-ss];
						str1[k]='\0';
						for(k1=0;k1<k;k1++)
							str[k1]=str1[k1];
						str[k1]='\0';
						break;
					}
				}
			}
			if(j!=m)
			{
				m=m+ss;
				i--;
			}
		
		}
		printf("%s\n",str);
	}
	return 0;
}


