#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
struct Node
{
	int x,y;
}node;

int main()
{
	int n,m;
	int *a=new int [1100000];
	scanf("%d%d",&n,&m);

	deque <Node> q,p;
	for (int i=0; i<n; i++)
	{
		int value;
		scanf("%d",&value);
		node.x=value; node.y=i;

		if (!q.empty() && q.front().y<=i-m)
			q.pop_front();
		if (!p.empty() && p.front().y<=i-m)
			p.pop_front();

		if (q.empty()) q.push_back(node);
		else
		{
			while (!q.empty() && q.back().x<=value)
				q.pop_back();
			q.push_back(node);
		}
		if (p.empty()) p.push_back(node);
		else
		{
			while (!p.empty() && p.back().x>=value)
				p.pop_back();
			p.push_back(node);
		}

		if (i>=m-1) {printf("%d",p.front().x); if (i!=n-1) printf(" "); a[i]=q.front().x;}
	}
	printf("\n");
	for (int i=m-1; i<n-1; i++) printf("%d ",a[i]);
	printf("%d\n",a[n-1]);
}