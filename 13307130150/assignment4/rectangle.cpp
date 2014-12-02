#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
struct Node
{
	int x,y;
}node;

int main()
{
	int n,h;
	stack <Node> q;
	scanf("%d",&n);
	while (n!=0)
	{
		long long ans=0,tot,t;
		for (int i=0; i<n;i++)
		{
			scanf("%d",&h);
			t=0;
			while (!q.empty() && h<=q.top().x)
			{
				tot=q.top().x*(q.top().y+t);
				if (tot>ans) ans=tot;
				t=t+q.top().y;
				q.pop();
			}
			node.x=h;
			node.y=1+t;
			q.push(node);
		}

		t=0;
		while (!q.empty())
		{
			tot=q.top().x*(q.top().y+t);
			if (tot>ans) ans=tot;
			t=t+q.top().y;
			q.pop();
		}
		printf("%lld\n",ans);
		scanf("%d",&n);
	}
}