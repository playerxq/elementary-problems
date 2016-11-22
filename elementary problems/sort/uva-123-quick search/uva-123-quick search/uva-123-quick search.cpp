// uva-123-quick search.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <cctype>
#include <ctype.h>
#include <algorithm>
using namespace std;

int main()
{
	set<string> o;
	multimap<string,string> r;
	string st;
	string k;
	while(cin>>k&&k != "::")
		o.insert(k);
	getchar();
	while(getline(cin,st))
	{
		for(int i = 0;i<st.size();i++)
			st[i] = tolower(st[i]);
		for(int i = 0;i<st.size();i++)
		{
			if(!isalpha(st[i])) continue;
			string t;
			int start_word = i;
			while(i<st.size()&&isalpha(st[i]))
				t+=st[i++];
			if(!o.count(t))
			{
				for (int j = 0; j < t.size(); j++)  
                    t[j] = toupper(t[j]); 
				string temp = st;
				temp.replace(start_word,t.size(),t);
				r.insert(make_pair(t,temp));
			}

		}

	}
	for (multimap<string, string>::iterator i = r.begin(); i != r.end(); i++)  
        cout << i -> second << endl; 
	return 0;
}

