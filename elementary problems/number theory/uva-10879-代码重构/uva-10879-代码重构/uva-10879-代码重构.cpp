// uva-10879-�����ع�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int cnt = 0;
	int num = 0;
	scanf("%d",&N);
	while(N--)
	{
		long n;
		num++;
		cnt = 0;
		scanf("%ld",&n);
		cout << "Case #" << num << ":" << " " << n;
		for(int j = 2; j < sqrt((double)n); ++j)
		{  
            if(n%j == 0){  
                cout << " = " << j << " * " << n/j;  
                cnt++;  
            }  
            if(cnt == 2){  
                break;  
            }  
        }
		cout << endl;
	}
	return 0;
}

