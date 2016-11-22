// uva-10392-大数分解.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define max 1000001
int is_prime[max];
int cnt;
void get_prime()
{
	memset(is_prime,1,sizeof(is_prime));
	int n = sqrt((double)max)+1;
	is_prime[1] = 1;
	is_prime[2] = 1;
	for(int i = 2;i<=n;i++)
	{
		if(is_prime[i])
		{
			for(int j = i+i;j<max;j+=i)
				is_prime[j] = 0;
		}
	}
}
int main()
{
	long long n;
	get_prime();
	while(scanf("%lld",&n))
	{
		if(n<=0)
			break;
		while(1)
		{
			int flag = 1;
			int i;
			for(i = 2;i<=n-1;i++)
			{
				if(i<=1000000)
				{
					if((is_prime[i])&&(n%i==0))
					{
						printf("    %lld\n",i);  
                        break; 
					}
				}
				else
				{
					flag = 0;
					break;
				}
			}
			if(i==n&&flag==1)  
            {  
                printf("    %lld\n",n);  
                break;  
            }else if(flag==0)  
            {  
                printf("    %lld\n",n);  
                break;  
            }  
            n=n/i;
		}
		printf("\n"); 
	}
	return 0;
}

