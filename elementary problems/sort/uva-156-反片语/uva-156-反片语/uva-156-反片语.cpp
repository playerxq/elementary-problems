// uva-156-反片语.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
char str[1000][25];  
char word[1000][25];  
  
int cmp_string(const void *_a, const void *_b)  
{  
    char *a = (char*)_a;  
    char *b = (char*)_b;  
    return strcmp(a,b);  
}  
  
int cmp_char(const void *_a, const void *_b)  
{  
    char *a = (char*)_a;  
    char *b = (char*)_b;  
    return *a - *b;  
}  
  
int main()  
{  
    char tp[25];  
    int sl = 0;  
    while (scanf("%s", tp), tp[0] != '#')  
    {  
        strcpy(str[sl++], tp);  
    }  
    qsort(str, sl, sizeof(str[0]), cmp_string);  
    for (int i = 0; i < sl; i++)  
    {  
        int len = strlen(str[i]);  
        for (int j = 0; j < len; j++)  
        {  
            word[i][j] = tolower(str[i][j]);
        }  
        qsort(word[i], len, sizeof(char), cmp_char);  
    }  
    for (int i = 0; i < sl; i++)  
    {  
        int num = 0;  
        for (int j = 0; j < sl; j++)  
        {  
            if (!strcmp(word[i], word[j]))  
                num++;  
        }  
        if (num == 1)  
            printf("%s\n", str[i]);  
    }  
  
    return 0;  
}

