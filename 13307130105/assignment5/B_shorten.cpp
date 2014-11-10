#include <bits/stdc++.h>

using namespace std;

int sb[256];
int (*sbfunc[256])(int,int);

void eval(stack<int>& stkNum,stack<int>& stkOp) {
	int b = stkNum.top(); stkNum.pop();
	int a = stkNum.top(); stkNum.pop();
	stkNum.push(sbfunc[stkOp.top()](a,b));
	stkOp.pop();
}

int add(int a,int b) { return a+b; }
int subtract(int a,int b) { return a-b; }
int multiply(int a,int b) { return a*b; }
int divide(int a,int b) { return a/b; }
int powie(int a,int b) {
	int x = 1;
	while(b--) x *= a;
	return x;
}

char expr[23333];
int blow(char*& cur)
{
	stack<int> stkNum, stkOp;
	while(*cur) {
		if(*cur >= '0' && *cur <= '9') {
			int numie = 0;
			while(*cur >= '0' && *cur <= '9') numie = numie * 10 + *cur++ - '0';
			stkNum.push(numie);
		}
		else if(strchr("+-*/^",*cur)) {
			while(!stkOp.empty() && (sb[stkOp.top()] <= sb[*cur] && *cur != '^')) eval(stkNum,stkOp);
			stkOp.push(*cur++);
		}
		else if(*cur == '(') stkNum.push(blow(++cur));
		else if(*cur == ')') { cur++; break; }
	}
	while(!stkOp.empty()) eval(stkNum,stkOp);
	return stkNum.top();
}

int main(void) {
	sb['+'] = sb['-'] = 9;
	sb['*'] = sb['/'] = 8;
	sb['^'] = 7;
	sbfunc['+'] = add; sbfunc['-'] = subtract; sbfunc['*'] = multiply; sbfunc['/'] = divide;
	sbfunc['^'] = powie;
	while(gets(expr) && *expr) {
		char* cur = expr;
		printf("%d\n",blow(cur));
	}
	return 0;
}
