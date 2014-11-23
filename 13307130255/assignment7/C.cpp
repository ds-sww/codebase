#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n,num;
	long long ans = 0;
	stack<int> a;
	ans = 0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		while(!a.empty()&&num>=a.top())
		{
			a.pop();
			ans += a.size();
		}
		a.push(num);
	}
	while(!a.empty())
	{
		a.pop();
		ans += a.size();
	}
	cout<<ans<<endl;
	return 0;
}
