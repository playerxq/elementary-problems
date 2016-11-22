// uva-424-整数查询.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define max 1100
char s[max];
int s1[max];
int s2[max];
void Add(char *str)
{
    int i,j;
    for (j=max,i=strlen(str)-1; i>=0; j--,i--)  s1[j]+=str[i]-'0';
    for (j=max; j>=0; j--)
        if (s1[j]>9)
        {
            s1[j]-=10;
            s1[j-1]+=1;
        }
    return;
}
int main()
{
    int i;
    char num[max];
    while(gets(num),strcmp(num,"0"))   Add(num);
    for (i=0; i<=max; i++)  if (s1[i]) break;
    for (; i<=max; i++)  printf("%d",s1[i]);
    printf("\n");
    return 0;
}

