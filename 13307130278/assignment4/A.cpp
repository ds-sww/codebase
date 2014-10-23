#include<iostream>
using namespace std;

int a[3000],b[3000],sta[3000];
int n;
int solve()
{
	int top = 0, now = 1;
	for (int i = 1; i <= n; i++)
	{
		++top; sta[top] = b[i];
		while ( (sta[top] == a[now])&&(top))
		{
			--top; ++now;
		}
	}
	while ((sta[top] == a[now]) && (top))
	{
		--top; ++now;
	}
	if (now > n)
		cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}


int main()
{
	cin >> n;
	while (n)
	{
		for (int i = 1; i <= n; i++)
			b[i] = i;
		while (true)
		{
			cin >> a[1];
			if (!a[1]) break;
			for (int i = 2; i <= n; i++)
				cin >> a[i];
			solve();
		}
		cout << endl;
		cin >> n;
	}
	return 0;
}