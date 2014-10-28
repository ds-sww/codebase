#include <iostream>
#include <cstdio>
using namespace std;

const int N = 2333;
const long long shift = 23333333333333LL;

int top;
long long stack[N];

int work(int a, int b, char c)
{
	if(c == '+')
		return a + b;
	if(c == '-')
		return a - b;
	if(c == '*')
		return a * b;
	if(c == '/')
		return a / b;
	int ret = 1;
	for(int i = 0; i < b; i++)
		ret *= a;
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	string s;
	while(cin >> s)
	{
		int tmp = 0;
		top = 0;
		s = '(' + s + ')';
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] >= '0' && s[i] <= '9')
				tmp = tmp * 10 + s[i] - '0';
			else if(s[i] != '(' && s[i] != ')')
			{
				if(stack[top - 1] > 256)
				{
					tmp = stack[top - 1] - shift;
					top --;
				}
				if(s[i] == '^')
					stack[top++] = tmp + shift;
				else if(s[i] == '*' || s[i] == '/')
				{
					while(stack[top - 1] == '^' || stack[top - 1] == '*' || stack[top - 1] == '/')
					{
						tmp = work(stack[top - 2] - shift, tmp, stack[top - 1]);
						top -= 2;
					}
					stack[top++] = tmp + shift;
				}
				else
				{
					while(stack[top - 1] == '^' || stack[top - 1] == '*' || stack[top - 1] == '/' 
					|| stack[top - 1] == '+' || stack[top - 1] == '-')
					{
						tmp = work(stack[top - 2] - shift, tmp, stack[top - 1]);
						top -= 2;
					}
					stack[top++] = tmp + shift;
				}
				stack[top++] = s[i];
				tmp = 0;
			}
			else if(s[i] == '(')
				stack[top++] = '(';
			else
			{
				if(stack[top - 1] < 256)
				{
					stack[top++] = tmp + shift;
					tmp = 0;
				}
				while(stack[top - 2] != '(')
				{
					stack[top - 3] = work(stack[top - 3] - shift, stack[top - 1] - shift, stack[top - 2]) + shift;
					top -= 2;
				}
				stack[top - 2] = stack[top - 1];
				top --;
			}
		}
		cout << stack[0] - shift << '\n';
	}
	return 0;
}