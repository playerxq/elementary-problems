// uva-10970-big chocolate.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int n, m;
    while( scanf( "%d%d", &n, &m) == 2)
    {
        int a = (n - 1) + n * ( m - 1);
        printf( "%d\n", a);
    }
    return 0;
}

