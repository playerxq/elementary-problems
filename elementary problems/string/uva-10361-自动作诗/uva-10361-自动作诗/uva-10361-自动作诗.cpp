// uva-10361-自动作诗.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
char s1[110];
char s2[110];
char s3[110];
int main()
{
	int T = 0;
	scanf("%d%*c",&T); 
	while(T--)
	{
		int t1,t2,t3,t4;
		t1 = -1;
		t2 = -1;
		t3 = -1;
		t4 = -1;
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(s3,0,sizeof(s3));
		gets(s1);
		gets(s2);
		int len_s1 = strlen(s1);
		int len_s2 = strlen(s2);
		for(int i = 0;i<len_s1;i++)
		{
			if(s1[i]=='<')
			{
				if(t1 == -1)
					t1 = i;
				else
					t3 = i;
			}
			if(s1[i]=='>')
			{
				if(t2 == -1)
					t2 = i;
				else
					t4 = i;
			}
		}
		int k = 0;
		for(int j = 0;j<len_s2-2;j++)
		{
			if(j<len_s2-3)
				s3[k++] = s2[j];
			else
			{
				for(int k1 = t3+1;k1<t4;k1++)
					s3[k++] = s1[k1];
				for(int k2 = t2+1;k2<t3;k2++)
					s3[k++] = s1[k2];
				for(int k3 = t1+1;k3<t2;k3++)
					s3[k++] = s1[k3];
				for(int k4 = t4+1;k4<len_s1;k4++)
					s3[k++] = s1[k4];
			}
		}
		for(int i = 0;i<len_s1;i++)
		{
			if((s1[i]!='<')&&(s1[i]!='>'))
				printf("%c",s1[i]);

		}
		printf("\n");
		int len_s3 = strlen(s3);
		for(int i = 0;i<len_s3;i++)
		{
				printf("%c",s3[i]);

		}
		printf("\n");
	}
	return 0;
}

