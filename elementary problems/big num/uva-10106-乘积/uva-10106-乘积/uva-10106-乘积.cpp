// uva-10106-乘积.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define max 550
int res[max];
char s1[260];
char s2[260];
void reverse(char a[])  
{  
    int len = strlen(a);  
    for (int i = 0; i < len / 2; i++)  
    {  
        char temp = a[i];  
        a[i] = a[len - 1 - i];  
        a[len - 1 - i] = temp;  
    }  
} 
void mul(char* s1, char* s2)
{
	int i,j;
	reverse(s1);  
    reverse(s2);
	int len_s1 = strlen(s1);
	int len_s2 = strlen(s2);
	for (i = 0; i < len_s1; i++)  
    {  
        for (j = 0; j < len_s2; j++)  
        {  
            res[i+j] = res[i + j] + (s1[i] - '0') * (s2[j] - '0');  
        }
    } 
	for(i = 0;i<len_s1+len_s2-1;i++)
	{
		if(res[i]>=10)
		{
			res[i+1] += res[i]/10;
			res[i] = res[i]%10;
		}
	}
	int len = 0;
	if(res[len_s1+len_s2-1])
		len = len_s1+len_s2;
	else
		len = len_s1+len_s2-1;
	if (strcmp(s1, "0") == 0 || strcmp(s2, "0") == 0) len = 1;  
    for (int t = len - 1; t >= 0; --t) cout << res[t];  
        cout << endl;
}
int main()
{
	
	while(scanf("%s%s",s1,s2)!=EOF)
	{
		memset(res,0,sizeof(res));
		mul(s1,s2);
	}
	return 0;
}

