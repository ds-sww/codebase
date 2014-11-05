#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef vector< pair<bool, int> > Expression;

int prior[128];

int power(int x, int n)
{
	int s=1;
	while (n)
	{
		if (n&1) s*=x;
		x*=x;
		n>>=1;
	}
	return s;
}

void trans(const string &str, Expression &expr)
{
	int len=str.size();
	expr.clear();
	stack<char> sta;
	for (int i=0; i<len; ++i)
		switch (str[i])
		{
			case ')':
				while (sta.top()!='(')
				{
					expr.push_back(make_pair(0, sta.top()));
					sta.pop();
				}
				sta.pop();
				break;
			case '(':
				sta.push(str[i]);
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				while (!sta.empty() && prior[sta.top()]>=prior[str[i]])
				{
					expr.push_back(make_pair(0, sta.top()));
					sta.pop();
				}
				sta.push(str[i]);
				break;
			case '^':
				while (!sta.empty() && prior[sta.top()]>prior[str[i]])
				{
					expr.push_back(make_pair(0, sta.top()));
					sta.pop();
				}
				sta.push(str[i]);
				break;
			default:
				int x=0;
				while (i<len && str[i]>='0' && str[i]<='9')
				{
					x=x*10+str[i]-'0';
					++i;
				}
				--i;
				expr.push_back(make_pair(1, x));
		}
	while (!sta.empty())
	{
		expr.push_back(make_pair(0, sta.top()));
		sta.pop();
	}
}

int calc(const Expression &expr)
{
	int x, y, z;
	stack<int> sta;
	for (int i=0; i<expr.size(); ++i)
		if (expr[i].first) sta.push(expr[i].second); else
		{
			y=sta.top();
			sta.pop();
			x=sta.top();
			sta.pop();
			switch (expr[i].second)
			{
				case '+':
					z=x+y; break;
				case '-':
					z=x-y; break;
				case '*':
					z=x*y; break;
				case '/':
					z=x/y; break;
				case '^':
					z=power(x, y); break;
			}
			sta.push(z);
		}
	return sta.top();
}

int main()
{
	prior['(']=0;
	prior['+']=prior['-']=1;
	prior['*']=prior['/']=2;
	prior['^']=3;

	string str;
	Expression expr;
	while (cin>>str)
	{
		trans(str, expr);
		cout<<calc(expr)<<endl;
	}
	return 0;
}
