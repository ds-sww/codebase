#include<cstdio>
#include<stack>
#include<iostream>
using namespace std;
const int MAXN = 10001;
int num[MAXN],p[MAXN];
int l,l2,ad,adr,tmp,tmp1,tmp2,now;
stack<char> s,s2;
stack<int> sp,snum,snum2;
char a[MAXN];
char b[MAXN];
int inop(char c)
{
	switch (c)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		case '^':return 3 + adr;
		default:return 0;
	}
	
}
int main()
{
	while (scanf("%s",a)!=-1)
	{
		l = 0;
		while (a[l]!='\0') l++;
		adr = 0;
		ad = 0;
		for (int i = 0; i<l; i++)
		{
			if (a[i]=='(') ad += 1000;
			if (a[i]==')') ad -= 1000;
			if (a[i]=='^') adr += 1;
			if (a[i]=='-' && (i==0 || a[i - 1]=='('))
				a[i]='A';
			else
			if (inop(a[i])>0)
				p[i] = ad + inop(a[i]);
		}
		int i = 0;
		l2 = 0;
		s.push('$');
		sp.push(-1);
		while (i<l)
		{
			if (a[i]=='A')
			{
				i++;
				tmp = a[i] - '0';
				tmp = 0 - tmp;
				i++;
				while (i<l && a[i]>='0' && a[i]<='9')
				{
					tmp = tmp * 10 - a[i] + '0';
					i++;
				}
				s2.push('a');
				snum.push(tmp);
			}
			else
			if (a[i]>='0' && a[i]<='9')
			{
				tmp = a[i] - '0';
				i++;
				while (i<l && a[i]>='0' && a[i]<='9')
				{
					tmp = tmp * 10 + a[i] - '0';
					i++;
				}
				s2.push('a');
				snum.push(tmp);
			}
			else
			if (inop(a[i])>0)
			{
				while (p[i]<=sp.top())
				{
					s2.push(s.top());
					sp.pop();
					s.pop();
				}
				sp.push(p[i]);
				s.push(a[i]);
				i++;
			}
			else i++;
		}
		while (!s.empty())
		{
			s2.push(s.top());
			s.pop();
		}
		s2.pop();//throw out $
		while (!s2.empty())
		{
			s.push(s2.top());
			s2.pop();
		}
		while (!snum.empty())
		{
			snum2.push(snum.top());
			snum.pop();
		}
		now = 0;
		while (!s.empty())
		{
			if (s.top()=='a')
			{
				snum.push(snum2.top());
				snum2.pop();
				s.pop();
				now++;
			}
			else
			{
				tmp2=snum.top();
				snum.pop();
				tmp1=snum.top();
				snum.pop();
				switch (s.top())
				{
					case '+':tmp = tmp1 + tmp2; break;
					case '-':tmp = tmp1 - tmp2; break;
					case '*':tmp = tmp1 * tmp2; break;
					case '/':tmp = tmp1 / tmp2; break;
					case '^':
						{
							tmp = 1;
							for (int i = 0; i<tmp2; i++)
								tmp *= tmp1;
							break;
						}
				}
				s.pop();
				snum.push(tmp);
			}
		}
		printf("%d\n",snum.top());
		snum.pop();
		while (!sp.empty()) sp.pop();
	}
	return 0;
}
