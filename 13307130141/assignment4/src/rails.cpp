#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1211;

int out[N];
int stack[N];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	bool printed = false;
	while(cin >> n)
	{
		if(n == 0)
			break;
		/*
		if(printed)
			cout << '\n';
		*/
		while(cin >> out[1])
		{
			if(out[1] == 0)
				break;
			for(int i = 2; i <= n; i++)
				cin >> out[i];

			bool flag = true;
			int top = 0;
			int used = 0;
			for(int i = 1; i <= n; i++)
			{
				while(top == 0 || stack[top - 1] != out[i])
					if(used != n)
					{
						used ++;
						stack[top++] = used;
					}
					else
					{
						flag = false;
						break;
					}

				if(flag)
					top --;
				else
					break;
			}

			if(flag)
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		//printed = true;
		cout << '\n';
	}
	return 0;
}