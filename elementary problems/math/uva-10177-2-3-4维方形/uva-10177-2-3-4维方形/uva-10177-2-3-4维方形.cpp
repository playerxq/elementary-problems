// uva-10177-2-3-4ά����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

  
int main()  
{  
    int N;  
    long long s2,r2,s3,r3,s4,r4;  
    while (scanf("%d", &N) != EOF)  
    {  
        s2 = N * (N + 1) * (2 * N + 1) / 6;//�����εĸ�������2ά��ƽ����ͣ�3ά��3�η���ͣ�4ά���Ĵη����  
        r2 = (N + 1) * N * N * (N + 1) /4;//ÿ����ȡ�����ߣ�Ȼ����ܵõ����о��ε��������������Σ���n+1��ȡ2����������м�������˼��Σ���ͬ  
        s3 = r2;  
        r3 = (N + 1) * N * N * (N + 1) * N * (N + 1) / 8;  
        s4 = (6*N*N*N*N*N + 15*N*N*N*N + 10*N*N*N - N) / 30;  
        r4 = (N + 1) * N * N * (N + 1) * N * (N + 1) * N * (N + 1)/16;  
  
        printf("%lld %lld %lld %lld %lld %lld\n",s2, r2 - s2, s3, r3 - s3, s4, r4 - s4);  
    }  
    return 0;  
}

