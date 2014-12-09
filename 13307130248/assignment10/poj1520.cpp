#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
int len, tnum;
char buffer[1000000];
vector<int> num, pstr;
vector<string> str, str2;
vector<bool> flag;

bool isNum()
{
	int f = sscanf(buffer, "%d", &tnum);
	if(f == 0) return false;

	int lennum = (tnum == 0) ? 1 : (int)(log10(abs(tnum))) + 1;
	lennum += (tnum < 0);
	
	if(lennum == len) return true;
	return false;
}

bool input()
{
	N = 0;
	flag.clear();
	str.clear();
	str2.clear();
	num.clear();
	while(scanf("%s", buffer))
	{
		if(buffer[0] == '.') break;
		++N; 

		len = strlen(buffer) - 1;
		char append = buffer[len];
		buffer[len] = '\0';
		
		if(isNum())
		{
			num.push_back(tnum);
			flag.push_back(false);
		}
		else
		{
			str.push_back(string(buffer));
			for(int i = 0; i < len; i++) buffer[i] = tolower(buffer[i]);
			str2.push_back(string(buffer));
			flag.push_back(true);
		}

		if(append == '.') break;
	}

	return buffer[0] != '.';
}

bool cmp(const int &a, const int &b)
{
	return str2[a] < str2[b];
}

int main()
{
	while(input())
	{
		sort(num.begin(), num.end());

		pstr.clear();
		for(int i = 0; i < str.size(); i++) pstr.push_back(i);
		sort(pstr.begin(), pstr.end(), cmp);
		
		vector<int>::iterator itnum = num.begin();
		vector<int>::iterator itpstr = pstr.begin();
		for(int i = 0; i < N; i++)
		{
			if(flag[i])
				printf("%s", str[*itpstr++].c_str());
			else
				printf("%d", *itnum++);
			
			if(i < N - 1) 
				printf(", ");
			else
				printf(".\n");
		}
	}
	return 0;
}
