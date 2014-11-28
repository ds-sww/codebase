#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

int N;

class Heap
{
private:
	vector<int> tree;

	void up(int x)
	{
		while(x)
		{
			if(tree[x] > tree[(x - 1) / 2])
			{
				swap(tree[x], tree[(x - 1) / 2]);
				x = (x - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}

	void down(int x)
	{
		while(x * 2 + 1 < tree.size())
		{
			if(x * 2 + 2 < tree.size())
			{
				int &m = tree[x * 2 + 1] > tree[x * 2 + 2] ? tree[x * 2 + 1] : tree[x * 2 + 2];
				int nx = tree[x * 2 + 1] > tree[x * 2 + 2] ? x * 2 + 1 : x * 2 + 2; 
				if(tree[x] < m)
				{
					swap(tree[x], m);
					x = nx;
				}
				else
				{
					break;
				}
			}
			else
			{
				if(tree[x] < tree[x * 2 + 1])
				{
					swap(tree[x], tree[x * 2 + 1]);
					x = x * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
	}

public:

	int top()
	{
		assert(tree.size());
		return tree[0];
	}

	void pop()
	{
		assert(tree.size());
		tree[0] = tree[tree.size() - 1];
		tree.erase(tree.end() - 1);
		down(0);
	}

	void push(int v)
	{
		tree.push_back(v);
		up(tree.size() - 1);
	}

	int size()
	{
		return tree.size();
	}

	bool empty()
	{
		return tree.empty();
	}

	void debug()
	{
		for(int i = 0; i < tree.size(); i++)
		{
			cout << tree[i] << " ";
		}
		cout << endl;
	}
}H;

void init()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		H.push(-tmp);
	}
}

void work()
{
	long long sum = 0;
	while(H.size() > 1)
	{
		int num1 = -H.top();
		H.pop();

		int num2 = -H.top();
		H.pop();

		H.push(-(num1 + num2));
		sum += num1 + num2;
	}

	cout << sum << endl;
}

void test()
{
	vector<int> v(10);
	N = 8;
	for(int i = 0; i < N; i++)
	{
		v[i] = i;
	}

	
	for(int i = 1; i < N; i++)
	{
		swap(v[i], v[rand() % i]);
	}

	for(int i = 0; i < N; i++)
	{
		H.push(v[i]);
	}

	for(int i = 0; i < N; i++) cout << v[i] << " ";
	cout << endl;

	for(int i = 0; i < N; i++)
	{
		cout << H.top() << " ";
		H.pop();
	}
	cout << endl << endl;
}

void test2()
{
	//6 0 1 2 5 3 7 4
	H.debug();
	for(int i = 0; i < N; i++)
	{
		cout << H.top() << " ";
		H.pop();
		H.debug();
	}
}

int main()
{
	//srand(time(0));
	init();
	//for(int i = 0; i < 100; i++) test();
	//test2();
	work();
	return 0;
}