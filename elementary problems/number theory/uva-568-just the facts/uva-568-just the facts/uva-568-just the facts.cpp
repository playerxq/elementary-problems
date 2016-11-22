// uva-568-just the facts.cpp : 定义控制台应用程序的入口点。
//如果4位数最后一位不为0  另一个一样  则其乘积不可能全为0 至多最后一位为0 因此运算只需看最后四位即mod10000

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define MAX_N 10000  
#define MAX_BIT 100000 
int main()
{
	 unsigned rslt[MAX_N+10];  
    unsigned bit = 1;  
    memset(rslt, 0, sizeof(rslt));  
    rslt[0] = 1;  
    for (unsigned i = 1; i <= MAX_N; i++) {  
        unsigned a = rslt[i-1];  
        unsigned b = i;  
        while (b % 10 == 0) {  
            b /= 10;  
        }  
        unsigned tp = a * b;  
        while (tp % 10 == 0) {  
            tp /= 10;  
        }  
        rslt[i] = tp % MAX_BIT;   
    }  
  
    unsigned n;  
    while (scanf("%d", &n) == 1) {  
        printf("%5d -> %d\n", n, rslt[n] % 10);  
    }  
  
    return 0;  
}

