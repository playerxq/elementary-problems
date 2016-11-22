// uva-10785-疯狂.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define INF 0xffffff7 
char val[] = "12345678912345678912345678";  
int used[26];
char name[256];
char name1[256];
char name2[256];
bool is_vowel(char a)
{
	 if ( (a != 'A') && (a != 'E') && (a != 'I') && (a != 'O') && (a != 'U') )  
        return false;  
    else  
        return true;  
}
int cmp(const void* c1, const void* c2)
{
	return *(char*)c1-*(char*)c2;
}
int main()
{
	int N;
	int num = 0;
	scanf("%d",&N);
	while(N--)
	{
		num++;
		int len = 0;
		memset(used,0,sizeof(used));
		memset(name,0,sizeof(name));
		memset(name1,0,sizeof(name1));
		memset(name2,0,sizeof(name2));
		int index_name1 = 0;
		int index_name2 = 0;
		scanf("%d",&len);
		int p = 0;
		for(;p<len;p++)
		{
			if(p%2==0)
			{
				 if (used['A' - 'A'] < 21)  
                {  
                    name1[index_name1++] = 'A';
                    used['A' - 'A']++;  
                }  
                else if (used['U' - 'A'] < 21)  
                {  
                    name1[index_name1++] = 'U';
                    used['U' - 'A']++;  
                }  
                else if (used['E' - 'A'] < 21)  
                {  
                    name1[index_name1++] = 'E';
                    used['E' - 'A']++;  
                }  
                else if (used['O' - 'A'] < 21)  
                {  
                    name1[index_name1++] = 'O';
                    used['O' - 'A']++;  
                }  
                else  
                {  
                    name1[index_name1++] = 'I'; 
                    used['I' - 'A']++;  
                } 
			}
			else
			{
				int v = INF;  
                int pos;  
                for (int j = 0; j < 26; j++)  
                {  
                    if (used[j] < 5 && !is_vowel('A' + j))  
                    {  
                        if ( (val[j]) < v)  
                        {  
                            v = val[j];  
                            pos = j;  
                        }  
                    }  
                }  
                name2[index_name2++]= ('A' + pos);  
                used[pos]++; 
			}
		}
		qsort(name1,index_name1,sizeof(char),cmp);
		qsort(name2,index_name2,sizeof(char),cmp);
		int k = 0;
		int l = 0;
		for(int i = 0;i<len;i++)
		{
			if(i%2==0)
			{
				//put vowel
				name[i] = name1[k]; 
                k++;
			}
			else
			{
				name[i] = name2[l];
				l++;
			}
		}
		printf("Case %d: %s\n",num,name);
	}
	return 0;
}
