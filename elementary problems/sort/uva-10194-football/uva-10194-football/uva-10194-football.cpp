// uva-10194-football.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
struct node
{
    char name[40];
    int point,play,win,tie,lose,score,again;
    void fun(int a,int b)
    {
        play++;
        if(a>b){win++;point+=3;}
        else if(a==b) {tie++;point+=1;}
        else lose++;
        score+=a;   again+=b;
    }
}team[35];
bool strcascmp(const char* str1, const char* str2)
{
	int len_s1 = strlen(str1);
	int len_s2 = strlen(str2);
	int i,j = 0;
	char c1,c2;
	for(i = 0,j = 0;i<len_s1&&j<len_s2;i++,j++)
	{
		c1 = str1[i];
		c2 = str2[j];
		if(isalpha(str1[i]))
			c1 = tolower(str1[i]);
		if(isalpha(str2[j]))
			c2 = tolower(str2[j]);
		if(c1<c2)
			return -1;
		else if(c1>c2)
			return 1;
		else
			continue;
	}
	if(i<len_s1)
		return 1;
	else if(j<len_s2)
		return -1;
	return 0;
}

bool cmp(const node &e1,const node &e2)
{
    if(e1.point!=e2.point) return e1.point>e2.point;
    else if(e1.win!=e2.win) return e1.win>e2.win;
    else if(e1.score-e1.again!=e2.score-e2.again) return e1.score-e1.again>e2.score-e2.again;
    else if(e1.score!=e2.score) return e1.score>e2.score;
    else if(e1.play!=e2.play) return e1.play<e2.play;
    else return strcascmp(e1.name,e2.name)<0;
}
int main()
{
    int t,t_cnt=0;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        char game[105]={0},temp[40],str[1005];
        int n,m,d=0;
        map<string,int> adj;
        memset(team,0,sizeof(team));

        gets(game);
        scanf("%d",&n);
        getchar();
        for(int i=0;i<n;i++)
        {
            gets(temp);
            adj.insert(pair<string,int>(temp,++d));
            strcpy(team[d].name,temp);
        }
        scanf("%d",&m);
        getchar();
        for(int i=0;i<m;i++)
        {
            char name1[40]={0},name2[40]={0};
            int num1,num2;
            gets(str);
            sscanf(str,"%[^#]#%d@%d#%[^\n]",name1,&num1,&num2,name2);
            //printf("name1=%s,num1=%d,name2=%s,num2=%d\n",name1,num1,name2,num2);
            team[adj[name1]].fun(num1,num2);
            team[adj[name2]].fun(num2,num1);
        }
        sort(team+1,team+n+1,cmp);
        if(t_cnt!=0) puts("");  t_cnt++;
        puts(game);
        for(int i=1;i<=n;i++)
        {
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i,
                   team[i].name,team[i].point,team[i].play,team[i].win,team[i].tie,
                   team[i].lose,team[i].score-team[i].again,team[i].score,team[i].again);
        }
    }
    return 0;
}
