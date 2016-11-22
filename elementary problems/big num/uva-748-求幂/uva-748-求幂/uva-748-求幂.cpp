// uva-748-求幂.cpp : 定义控制台应用程序的入口点。
//

// poj-1001.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
char str[10];  
int n, dot;  
int res[999999], a[999999], b[999999];  
int len, lena, lenb;  
  
void mul()  
{  
    int i, j;  
    memset(res, 0, sizeof(res));  
    for (i=0; i<lena; i++)  
    {  
        for (j=0; j<lenb; j++)  
        {  
            res[i+j] += a[i] * b[j];  
        }  
    }  
	for(i = 0;i<lena+lenb-1;i++)
	{
		if(res[i]>=10)
		{
			res[i+1] += res[i]/10;
			res[i] = res[i]%10;
		}
	}
	if(res[lena+lenb-1])
		lena+=lenb;
	else
		lena = lena+lenb-1;
	memset(a,0,sizeof(a));
    for (i=0; i<lena; i++) a[i] = res[i];  

}  
  
int main()  
{  
    int i, j, up, down;  
    while (scanf("%s %d", str, &n)!=EOF)  
    {  
        dot = -1;  
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(res,0,sizeof(res));
        for (i=5, j=0; i>=0; i--)  
        {  
            if (str[i]!='.') a[j] = b[j++] = str[i] - '0';  
            else dot = i;  
        }  
        if (dot==-1) lena = lenb = 6;  
        else lena = lenb = 5;  
        for (i=1; i<n; i++) mul();  
        if (dot==-1)   
        {  
            for (i=lena-1; i>=0; i--) printf("%d", a[i]);  
            printf("\n");  
        }  
        else  
        {  
            dot = 5 - dot;  //逆序中小数点位置
            dot *= n;  
            for (i=0; i<lena; i++)  
            {  
                if (a[i]!=0)  
                {  
                    down = i;  
                    break;  
                }  
            }  
            for (j=lena-1; j>=0; j--)  
            {  
                if (a[j]!=0)  
                {  
                    up = j;  
                    break;  
                }  
            }  
            i = up;  
            if (up<dot) i = dot;  
            j = down;  
            if (j>dot) j = dot+1 ;  
            for (; i>=j; i--)  
            {               
                printf("%d", a[i]);  
				if (i==dot) printf(".");  
            }  
            printf("\n");  
        }  
    }  
    return 0;  
} 




