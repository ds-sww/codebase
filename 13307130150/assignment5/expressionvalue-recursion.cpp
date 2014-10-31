//看了助教代码后写的，但是一开始很多细节自己理解的不太对
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
class calcu
{
private:
	string expre;
	int cur;
	bool end()
	{
		return cur == expre.size();
	}
	int pow(int a,int index)
	{
		int tot = 1;
		for (int i = 0; i < index; i++)
			tot *= a;
		return tot;
	}
	int prio0()
	{
		int val = prio1();
		while (!end() && (expre[cur] == '+' || expre[cur] == ‘-‘))
                //这里开始写的是if，结果调了好久，因为2*2*2*2这样的就会出问题
		{
			if (expre[cur++] == '+')
			{
				int temp = prio1();
				val += temp;
			}
			else
			{
				int temp = prio1();
				val -= temp;
			}
		}
		return val;
	}
	int prio1()
	{
		int val = prio2();
		while (!end() && (expre[cur] == '*' || expre[cur] == '/'))
		{
			if (expre[cur++] == '*')
			{
				int temp = prio2();
				val *= temp;
			}
			else
			{
				int temp = prio2();
				val /= temp;
			}
		}
		return val;
	}
	int prio2()
	{
		int val = prio3();
		if (!end() && expre[cur] == '^')
		{
			cur++;
			int temp = prio2();   //乘方的优先级处理很特别，开始也忽略了。
			val = pow(val,temp);
		}
		return val;
	}
	int prio3()
	{
		int val = 0;
		if (!end() && expre[cur] == '(')
		{
			cur++;
			val = prio0();
			cur++;
		}
		else
		{
			while (!end() && expre[cur] >= '0' && expre[cur] <= '9')
			{
				val = val * 10 + expre[cur] - '0';
				cur++;
			}
		}
		return val;
	}
public:
	calcu(const string & str):expre(str),cur(0){}
	void cal()
	{
		cur = 0;
		cout << prio0() <<endl;
	}
};
int main()
{
	string expression;
	while (cin >> expression)
	{
		calcu value(expression);
		value.cal();
	}
}