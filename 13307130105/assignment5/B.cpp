#include <bits/stdc++.h>

using namespace std;

char expr[23333];
int sb[256];

int eval(stack<int>& stkNum,stack<int>& stkOp)
{
	int b = stkNum.top(); stkNum.pop();
	int a = stkNum.top(); stkNum.pop();
	switch(stkOp.top())
	{
		case '+': stkNum.push(a+b); break;
		case '-': stkNum.push(a-b); break;
		case '*': stkNum.push(a*b); break;
		case '/': stkNum.push(a/b); break;
		case '^':
		{
			int x = 1;
			while(b--) x *= a;
			stkNum.push(x);
			break;
		}
	}
	stkOp.pop();
	return 0;
}

int blow(char*& cur)
{
	stack<int> stkNum;
	stack<int> stkOp;
	while(*cur)
	{
		int ch = *cur;
		if(ch >= '0' && ch <= '9')
		{
			int numie = 0;
			while(*cur >= '0' && *cur <= '9') numie = numie * 10 + *cur++ - '0';
			stkNum.push(numie);
		}
		else if(strchr("+-*/^",ch))
		{
			while(!stkOp.empty() && (sb[stkOp.top()] <= sb[ch] && !(stkOp.top() == '^' && ch == '^'))) eval(stkNum,stkOp);
			stkOp.push(ch);
			cur++;
		}
		else if(ch == '(')
		{
			// FINALLY IT IS CONTEXT-FREEEEEEEEEEEEEEEEEEEEEEEEEE
			// (at least, "relatively")
			stkNum.push(blow(++cur));
		}
		else if(ch == ')')
		{
			cur++;
			break;
		}
	}
	while(!stkOp.empty()) eval(stkNum,stkOp);
	int result = stkNum.top();
	return result;
}

int main(void)
{
	memset(sb,-1,sizeof(sb));
	// fuck those non context-free things
	sb['+'] = sb['-'] = 9;
	sb['*'] = sb['/'] = 8;
	sb['^'] = 7;
	// ---------------_,-----------------
	while(gets(expr) && *expr)
	{
		char* cur = expr;
		printf("%d\n",blow(cur));
	}
	return 0;
}
