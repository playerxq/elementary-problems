// uva-621-secret research.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define max 10000
char s[max];
int main()
{
	int n = 0;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		
		memset(s,0,sizeof(s));
		gets(s);
		int len = strlen(s);
		if((strcmp(s,"1")==0)||strcmp(s,"78")==0||strcmp(s,"4")==0)
			printf("+\n");
		else if((len>=2)&&((s[len-1]=='5')&&(s[len-2]=='3')))
			printf("-\n");
		else if((s[0]=='9')&&(s[len-1]=='4'))
		{
			printf("*\n");
		}
		else if((len>=3)&&(s[0]=='1')&&(s[1]=='9')&&(s[2]=='0'))
			printf("?\n");
	}
	return 0;
}

