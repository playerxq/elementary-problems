// uva-10815-第一个字典.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char s[1000001][201];
int cmp1(const void *a,const void *b)
{
     return strcmp((char *)a,(char *)b);
}
int main()
{
     int i,j;
     char c;
     i=0;j=0;
     while(scanf("%c",&c)!=EOF)       //(c=getchar())!=EOF 效率较高
     {
         if(isalpha(c))
              s[i][j++]=tolower(c);
         else if(j!=0)
         {
              s[i++][j]=0;
              j=0;
         }
     }
     qsort(s,i,sizeof(s[0]),cmp1);
     for(j=0;j<i;j++)
         if(j==0)
              printf("%s\n",s[j]);
         else if(strcmp(s[j-1],s[j]))//
              printf("%s\n",s[j]);
         return 0;
}

