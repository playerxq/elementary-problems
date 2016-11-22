// uva-408-���ȵ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdio>
#include<iomanip>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {  
    if(b==0)
		return a;
	while(b)
	{
		int c = a%b;
		a = b;
		b = c;
	}
	return a;
}  
int main() {  
    int step, mod;  
    while(~scanf("%d%d", &step, &mod)) {  
		
        printf("%10d%10d    ", step, mod);  
		if(step<mod) swap(step,mod);
        if(gcd(step, mod) == 1) printf("Good Choice\n\n");  
        else printf("Bad Choice\n\n");  
    }  
    return 0;  
} 

