// uva-10494-回到童年.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

int main()
{
	long num = 0;
	long temp = 0;
	long len = 0;
	long i = 0;
	long sum,pos = 0;
	sum = 0;
	char s[1000];
	char label;
	long a[1000];
	while(scanf("%s %c %ld",s,&label,&num)!=EOF)
	{
		len = strlen(s);
		sum = 0;
		if(label == '/')
		{
			temp = 0;
			for(i = 0;i<len;i++)
			{
				temp = temp*10+s[i]-'0';
				if(temp>=num)
				{
					++sum;
					a[sum] = temp/num;
					temp = temp%num;
				}
				else
				{
					a[++sum] = 0;
				}
			}
			 pos=1;
			 while ((a[pos]==0)&&(pos<sum)) ++pos;
			 for (i=pos;i<=sum;i++)
				printf("%ld",a[i]);
			printf("\n");
		}
		else
		{
			for(i = 0;i<len;i++)
			{
				sum = sum*10+s[i]-'0';
				sum = sum%num;
			}
			printf("%ld\n",sum);
		}
		memset(s,0,sizeof(s));
		memset(a,0,sizeof(a));
	}
	return 0;
}

