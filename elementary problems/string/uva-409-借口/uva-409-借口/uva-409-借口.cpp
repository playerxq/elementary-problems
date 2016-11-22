// uva-409-借口.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int k, e, count[20], max, len;
    int i, j, n = 1;
    char s_k[20][30], s_e[20][80], buf[80];
    while(scanf("%d%d", &k, &e) == 2)
    {
        max = 0;
        memset(count, 0, 30);
        for(i = 0; i < k; i++)  scanf("%s", s_k[i]);//关键字
        getchar();//因为用fgets读
        for(i = 0; i < e; i++)
        {
            memset(buf, 0, 80);
            fgets(s_e[i], 80, stdin);
            for(j = 0, len = strlen(s_e[i]); j < len; j++) buf[j] = tolower(s_e[i][j]);
            for(j = 0; j < k; j++)
            {
                char *c = buf;
                while((c = strstr(c, s_k[j])) != NULL)
                {
                    count[i]++;
                    c += strlen(s_k[j]);
                }
            }
            if(count[i] > max) max = count[i];
        }
        printf("Excuse Set #%d\n", n++);
        for(i = 0; i < e; i++)
            if(count[i] == max) printf("%s", s_e[i]);
              printf("\n");
     }
     return 0;
}

