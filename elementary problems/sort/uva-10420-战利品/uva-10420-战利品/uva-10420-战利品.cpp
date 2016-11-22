// uva-10420-战利品.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
char s[2100][80];
typedef struct conquest
{
	char country[75];
	int num;
	struct conquest operator = (const struct conquest coun)
	{
		int len = strlen(coun.country);
		int i  = 0;
		for(i = 0;i<len;i++)
		{
			country[i] = coun.country[i];
		}
		country[i] = '\0';
		num = coun.num;
		return *this;
	}
	struct conquest operator = (const char* s)
	{
		int len = strlen(s);
		int i = 0;
		for(i = 0;i<len;i++)
		{
			country[i] = s[i];
		}
		country[i] = '\0';
		num = 0;
		return *this;
	}
} Con;
Con coun_try[2100];

int cmp(const char* str1, const char* str2)
{
	int len_1 = strlen(str1);
	int len_2 = strlen(str2);
	int i,j;
	i = 0;
	j = 0;
	for(;i<len_1&&j<len_2;i++,j++)
	{
		if(tolower(str1[i])<tolower(str2[j]))
			return -1;
		else if(tolower(str1[i])==tolower(str2[j]))
			continue;
		else
			return 1;
	}
	if(i<len_1)
		return 1;
	else if(j<len_2)
		return -1;
	return 0;
}

int main()
{
	int n = 0;
	scanf("%d",&n);
	getchar();
	int len = 0;
	for(int i = 0;i<n;i++)
	{
		gets(s[i]);
		int j = 0;
		while(s[i][j]!=' ')
			j++;
		s[i][j] = '\0';
		int k = 0;
		for(;k<len;k++)
		{
			if(cmp(coun_try[k].country,s[i])==0)
			{
				coun_try[k].num++;
				break;
			}
			else if(cmp(coun_try[k].country,s[i])==-1)
				continue;
			else
			{
				for(int h = len-1;h>=k;h--)
				{
					coun_try[h+1] = coun_try[h];
				}
				coun_try[k] = s[i];
				len++;
				break;
			}
		}
		if(k==len)
		{
			coun_try[k] = s[i];
			len++;
		}
	}
    for(int o = 0;o<len;o++)
	{
		printf("%s %d\n",coun_try[o].country,coun_try[o].num+1);
	}
	return 0;
}

