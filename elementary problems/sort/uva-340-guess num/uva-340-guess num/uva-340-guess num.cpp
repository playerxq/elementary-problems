// uva-340-guess num.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define max 1000
int scode[max];
int guess[max];
int unmatch[max];
int main()
{
	int n = 0;
	int col = 0;
	while((scanf("%d",&n)==1)&&(n!=0))
	{
		col++;
		memset(scode,0,sizeof(scode));
		for(int i = 0;i<n;i++)
		{
			scanf("%d",&scode[i]);
		}
		cout<<"Game "<<col<<":"<<endl;
		while(1)
		{
			int strong, weak;
			strong = 0;
			weak = 0;
			memset(guess,0,sizeof(guess));
			for(int i = 0;i<n;i++)
				scanf("%d",&guess[i]);
			if(guess[0]==0)
				break;
			memset(unmatch,0,sizeof(unmatch));
			int index_unmatch = 0;
			for (int i=0;i<n;i++)  
            {  
                if (scode[i]==guess[i]) strong++;  
                else  
                {  
                    unmatch[index_unmatch++]=i;  //����δƥ�������
                }  
            }
			if (index_unmatch>0)  
            {  
                int scount[10]={0};  
                int gcount[10]={0};  
                for (int i=0;i<index_unmatch;i++)  
                {  
                    scount[scode[unmatch[i]]]++;    //scount[1]��ŵļ�1��scode�г��ִ���  
                    gcount[guess[unmatch[i]]]++;  
                }  
                for (int i=1;i<10;i++)  
                {  
                    weak=weak+(scount[i]<gcount[i]?scount[i]:gcount[i]); //ȡС����  
                }  
            } 
			cout<<"    ("<<strong<<","<<weak<<")"<<endl;
		}
	}
	return 0;
}

