#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>

#define MAX 10010

using namespace std;

int main()
{
	int i,j;
	int n,m;
	int a[MAX];
	stack<int> s;

	while(1)
	{
		cin >> n;
		if(n==0)
			break;
		while(1)
		{
			cin >> a[0];
			if(a[0] == 0)
			{
				cout << endl;
				break;
			}
			for(i = 1; i < n; i++)
				cin >> a[i];

			int l = 0;
			while(!s.empty())
				s.pop();
			for(i = 1; i <= n; i++)
			{
				s.push(i);
				while(!s.empty() && s.top() == a[l])
				{
					s.pop();
					l++;
				}
			}

			if(s.empty())
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 0;
}
