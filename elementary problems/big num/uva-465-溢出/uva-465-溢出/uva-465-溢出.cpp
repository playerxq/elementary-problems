// uva-465-溢出.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
const int INF = 0x7fffffff;
char s1[1000];
char s2[1000];
char label;
int main()
{
	while(scanf("%s %c %s",s1,&label,s2)==3)
	{
		double a,b;
		sscanf(s1, "%lf", &a);  
        sscanf(s2, "%lf", &b);
		printf("%s %c %s\n", s1, label, s2);  
        if (a > INF) {  
            printf("first number too big\n");  
        }  
        if (b > INF) {  
            printf("second number too big\n");  
        }  
        if (label == '+') {  
            if (a + b > INF) {  
                printf("result too big\n");  
            }  
        } else {  
            if (a * b > INF) {  
                printf("result too big\n");  
            }  
        } 
	}
	return 0;
}

