#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <deque>

#define MAX 1000010

using namespace std;

int main()
{
	int i,j;
	int n,k;
	int a[MAX],ans[MAX];
	deque<int> Q;
	
	cin >> n >> k ;
	for(i=0;i<n;i++)
		cin >> a[i];

	for(i=0;i<k;i++)
	{
		while(!Q.empty() && a[i] >= a[Q.back()])
			Q.pop_back();
		Q.push_back(i);
	}
	for(i=k;i<n;i++)
	{
		ans[i-k] = a[Q.front()];
		while(!Q.empty() && a[i] >= a[Q.back()])
			Q.pop_back();
		while(!Q.empty() && Q.front() <= i-k)
			Q.pop_front();
		Q.push_back(i);
	}
	ans[n-k] = a[Q.front()];

	for(i=0;i<n-k;i++)
		cout << ans[i] << ' ';
	cout << ans[n-k] << endl;

	Q.clear();

	for(i=0;i<k;i++)
	{
		while(!Q.empty() && a[i] <= a[Q.back()])
			Q.pop_back();
		Q.push_back(i);
	}
	for(i=k;i<n;i++)
	{
		ans[i-k] = a[Q.front()];
		while(!Q.empty() && a[i] <= a[Q.back()])
			Q.pop_back();
		while(!Q.empty() && Q.front() <= i-k)
			Q.pop_front();
		Q.push_back(i);
	}
	ans[n-k] = a[Q.front()];
 	
 	for(i=0;i<n-k;i++)
		cout << ans[i] << ' ';
	cout << ans[n-k] << endl;

	return 0;
}

