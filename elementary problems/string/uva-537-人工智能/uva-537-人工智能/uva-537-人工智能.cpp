// uva-537-�˹�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>
char s[1000];
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    int now=0;
    while(t--)
    {
        fgets(s,sizeof(s),stdin);
        printf("Problem #%d\n",++now);
        int i,j,w=0;
        double shu,U=0,I=0,P=0;
        for(i=0;s[i]!='\0';i++)
        {
            shu=0;
            if(s[i]=='=')
            {
                int fu=0;
                for(j=i+1;s[j]!='V'&&s[j]!='A'&&s[j]!='W';j++)
                {
                    if(s[j]=='M') shu*=1000000;//����M  
                    else if(s[j]=='k') shu*=1000;
                    else if(s[j]=='m') shu*=0.001;
                    else if(s[j]=='.') fu=j;//С����
                    else
                    {
                        if(fu==0)
                            shu=shu*10+s[j]-'0';
                        else
                            shu+=(s[j]-'0')*(pow(10,(fu-j)));
                    }
                }
                if(s[j]=='V') U=shu;
                else if(s[j]=='A') I=shu;
                else P=shu;
                if(w==0)
                {
                    w=1;//�õ�����ֵ����
                    i=j;
                }
                else break;
            }
        }
        if(U==0)
            printf("U=%.2lfV\n\n",P/I);
        else if(P==0)
            printf("P=%.2lfW\n\n",I*U);
        else if(I==0)
            printf("I=%.2lfA\n\n",P/U);
    }
    return 0;
}

