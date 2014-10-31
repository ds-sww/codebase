#include <iostream>
#include <cstdio>
#include "list.h"
using namespace std;
class Deque:public List
{
public:
	void push_head(int x)
	{
		insert(x,0);
	}
	int pop_head()
	{
		return remove(0);
	}
	void push_tail(int x)
	{
		insert(x,size()-1);
	}
	int pop_tail()
	{
		return remove(size()-1);
	}
};
int main()
{
	Deque a;
	a.create();
	cout<<a.pop_head()<<endl;
	cout<<a.pop_tail()<<endl;
	cout<<a.pop_head()<<endl;
	cout<<a.pop_tail()<<endl;
	a.push_head(1);
	a.push_tail(1);
	a.sort(0,a.size()-1);
	a.display();
	return 0;
}