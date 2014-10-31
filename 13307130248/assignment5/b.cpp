#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <stack>

using namespace std;

string expr;
stack<int> num;
stack<char> sym;
map<char, int> pri;

int convert(char ch)
{
	return pri[ch];
}

void init()
{
	pri['('] = -1;
	pri['^'] = 2;
	pri['*'] = pri['/'] = 1;
	pri['+'] = pri['-'] = 0;
	pri[')'] = -1;
}

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

void getNumber(int &i, int &val)
{
	val = 0;
	for(; i < expr.length(); i++)
	{
		if(isDigit(expr[i]))
		{
			val = val * 10 + expr[i] - '0';
		}else{
			break;
		}
	}
	i--;
}

int calc(char ch, int a, int b)
{
	int res;
	switch(ch)
	{
	case '^':
		res = 1;
		for(int i = 0; i < b; i++) res *= a;
		break;
	case '*':
		res = a * b;
		break;
	case '/':
		res = a / b;
		break;
	case '+':
		res = a + b;
		break;
	case '-':
		res = a - b;
		break;
	}
	return res;
}

bool judge(char top, char expr)
{
	if(top == '^' && expr == '^') return false;
	if(top == '(' && expr == ')') return false;
	return convert(top) >= convert(expr);
}

void work()
{
	while(!num.empty()) num.pop();
	while(!sym.empty()) sym.pop();
	
	//cout << expr << endl;
	
	for(int i = 0; i < expr.length(); i++)
	{
		if(isDigit(expr[i]))
		{
			int val, pos;
			getNumber(i, val);
			num.push(val);
		}else{
			if(expr[i] == '(')
			{
				sym.push('(');
				continue;
			}
			while(!sym.empty() && judge(sym.top(), expr[i]))
			{
				int a, b;
				b = num.top();
				num.pop();
				a = num.top();
				num.pop();
				
				int res = calc(sym.top(), a, b);

				sym.pop();
				num.push(res);

			}
			if(expr[i] == ')')
			{
				sym.pop();
				continue;
			}
			else
			{
				sym.push(expr[i]);
			}
		}
	}
	
	cout << num.top() << endl;
}

int main()
{
	init();
	while(cin >> expr)
	{
		expr = "(" + expr + ")";
		work();
	}
	return 0;
}