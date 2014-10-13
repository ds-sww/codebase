#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() 
{
	int n,sum = 0;
	priority_queue<int, vector<int, allocator<int> >, greater<int> > Q;
	cin >> n ;
	for(int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		Q.push(tmp);
	}
	for(int i = n-1; i > 0; i--)
	{
		int tmp = 0;
		tmp += Q.top();
		Q.pop();
		tmp += Q.top();
		Q.pop();
		Q.push(tmp);
		sum += tmp;
	}
	cout << sum << endl;
    return 0;
}