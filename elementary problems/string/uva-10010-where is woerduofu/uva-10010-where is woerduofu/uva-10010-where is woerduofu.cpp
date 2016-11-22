// uva-10010-where is woerduofu.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
char s[60][60];
char str[60];
int x;
int y;
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
bool ok(int i,int j,int m,int n)
{
	if((i>=0)&&(i<m)&&(j>=0)&&(j<n))
		return true;
	return false;
}
void find(char* str,int m,int n)
{
	int len = strlen(str);
	for(int i = 0;i<m;i++)
	{
		for(int j = 0;j<n;j++)
		{
			if(s[i][j] == str[0])
			{
				for(int k = 0;k<8;k++)//8方向查找
				{
					int l = len-1;
					int h = 1;
					for(;h<=l;h++)
					{
						if((!ok(i+h*dx[k],j+h*dy[k],m,n))||(str[h]!=s[i+h*dx[k]][j+h*dy[k]]))
							break;
					}
					if(h>l)
					{
						x = i+1;
						y = j+1;
						return;
					}
					else
						continue;
				}
			}
		}
	}
}
int main()
{
	int T = 0;
	int m = 0;
	int n = 0;
	int e = 0; 
	//freopen("../../../../input.txt","r",stdin);
	cin>>T;
	while(T--)
	{
		if(e != 0)  
            cout << endl;  
        e++;
		cin>>m>>n;
		for(int i = 0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
			{
				cin>>s[i][j];
				s[i][j] = tolower(s[i][j]);
			}
		}
		int t = 0;
		cin>>t;
		while(t--)
		{
			
			cin>>str;
			int len = strlen(str);
			for(int i = 0;i<len;i++)
				str[i] = tolower(str[i]);
			find(str,m,n);
			cout << x << " " << y << endl; 
		}
		memset(s,0,sizeof(s));
		memset(str,0,sizeof(str));
	}
	return 0;
}

