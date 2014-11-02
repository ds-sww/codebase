#include <iostream>
#include <string>
#include <stack>
using namespace std;
int change(int x,int y,char cal)
{
	int temp=1;
	switch (cal)
	{
	case'^':
		for (int i=0; i<y; i++)
			temp*=x;
		return temp;
	case'*':return x*y;
	case'/':return x/y;
	case'+':return x+y;
	case'-':return x-y;
	}
}
int outs(char cal)
{
	switch (cal)
	{
	case'^':return 4;
	case'*':
	case'/':return 2;
	case'+':
	case'-':return 1;
	}
}
int ins(char cal)
{
	switch (cal)
	{
	case'^':return 3;
	case'*':
	case'/':return 2;
	case'+':
	case'-':return 1;
	case'(':return 0;
	case'$':return -1;
	}
}
int main()
{
	string expre;
	stack <char> calsym;
	stack <int> suff;
	int x,flag,a,b;
	calsym.push('$');
	while (cin >> expre)
	{ 
		x = 0;
		flag = 0;
		for (int i = 0; i < expre.size(); i++)
		{
			if ('0' <= expre[i] && expre[i] <= '9')
			{
				x = x * 10 + (expre[i] - 48);
				flag = 1; continue;
			}
			if (flag == 1)
			{
				suff.push(x);
				x = 0;
				flag = 0;
			}
			switch (expre[i])
			{
				case'*':
				case'/':
				case'+':
				case'-':
				case'^':
					while (outs(expre[i]) <= ins(calsym.top()))
					{
						a=suff.top();
						suff.pop();
						b=suff.top();
						suff.pop();
						suff.push(change(b,a,calsym.top()));
						calsym.pop();
					}
					calsym.push(expre[i]);
					break;
				case'(':
					calsym.push(expre[i]);
					break;
				case')':
					while (calsym.top() != '(')
					{
						a=suff.top();
						suff.pop();
						b=suff.top();
						suff.pop();
						suff.push(change(b,a,calsym.top()));						
						calsym.pop();
					}
					calsym.pop();
					break;
			}
		}

		if (flag == 1)
		{
			suff.push(x);
		}
		while (calsym.top() != '$')
		{
		    a=suff.top();
			suff.pop();
			b=suff.top();
			suff.pop();
			suff.push(change(b,a,calsym.top()));
			calsym.pop();
		}
		cout << suff.top()<<endl;
		suff.pop();
	}
}