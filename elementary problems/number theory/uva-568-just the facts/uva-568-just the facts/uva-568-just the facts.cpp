// uva-568-just the facts.cpp : �������̨Ӧ�ó������ڵ㡣
//���4λ�����һλ��Ϊ0  ��һ��һ��  ����˻�������ȫΪ0 �������һλΪ0 �������ֻ�迴�����λ��mod10000

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

