// uva-10177-2-3-4维方形.cpp : 定义控制台应用程序的入口点。
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
        s2 = N * (N + 1) * (2 * N + 1) / 6;//正方形的个数就是2维，平方求和，3维，3次方求和，4维，四次方求和  
        r2 = (N + 1) * N * N * (N + 1) /4;//每个面取两条线，然后就能得到所有矩形的数（包括正方形）（n+1）取2的组合数，有几个面相乘几次，下同  
        s3 = r2;  
        r3 = (N + 1) * N * N * (N + 1) * N * (N + 1) / 8;  
        s4 = (6*N*N*N*N*N + 15*N*N*N*N + 10*N*N*N - N) / 30;  
        r4 = (N + 1) * N * N * (N + 1) * N * (N + 1) * N * (N + 1)/16;  
  
        printf("%lld %lld %lld %lld %lld %lld\n",s2, r2 - s2, s3, r3 - s3, s4, r4 - s4);  
    }  
    return 0;  
}

