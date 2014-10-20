#include<cstdio>
#include<cstdlib>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
struct T
{
	int v;
	T(){}
	T(int a) :v(a){}
	friend bool operator <(const T &t1, const T &t2)
	{
		return t1.v > t2.v;
	}
};
priority_queue<T> q;
int n,key;
int main()
{
	cin>>n;
	for (int i = 0; i < n; i++)
	{	
		cin>>key;
		q.push(T(key));
	}
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		int x = q.top().v; q.pop(); 
		int y = q.top().v; q.pop();	
		ans += x + y;
		q.push(T(x+y));
	}
	cout<<ans<<"\n";
	return 0;
}