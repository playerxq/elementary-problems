// uva-401-回文.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
char a[22]="AEHIJLMOSTUVWXYZ12358";  
char b[22]="A3HILJMO2TUVWXY51SEZ8";
char s[100000];
int is_p(char* s)
{
	if(s==NULL)
		return -1;
	int n = strlen(s);
	for(int i = 0;i<n/2;i++)
	{
		if(s[i]!=s[n-i-1])
			return 0;
	}
	return 1;
}
int is_m(char* s)
{
	int i,k;
	if(s==NULL)
		return -1;
	int n = strlen(s);
	if(n==1)
	{
		for(i = 0;i<21;i++)
		{
			if(s[0]==a[i])
				break;
		}
		if(i == 21||s[0]!=b[i])
			return 0;
		else
			return 1;
	}
	else
	{
		for(int j = 0;j<n/2+1;j++)
		{
			for(k = 0;k<21;k++)
			{
				if(s[j]==a[k])
					break;
			}
			if(k==21||b[k]!=s[n-j-1])
				return 0;
		}
		return 1;
	}
}
int main()
{
	int n1;
	int n2;
	n1 = -1;
	n2 = -1;
	while(gets(s)!=NULL)
	{
		n1 = is_p(s);
		n2 = is_m(s);
		if(n1==1)  
        {  
            if(n2==1)  
            printf("%s -- is a mirrored palindrome.\n\n",s);  
            else  
            printf("%s -- is a regular palindrome.\n\n",s);  
        }  
        else  
        {  
            if(n2==1)  
            printf("%s -- is a mirrored string.\n\n",s);  
            else  
            printf("%s -- is not a palindrome.\n\n",s);  
        } 
		memset(s,0,sizeof(s));
	}
	return 0;
}

