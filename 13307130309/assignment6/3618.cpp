#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
using namespace std;

int n,t;
int now,time,ans;

int x[100001];
int main()
{
	int i,j,l,r;
	scanf("%d%d",&t,&n);
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	sort(x,x+n);
	l=-1;
	for(i=0;i<n;i++)
	if(x[i]<0&&(i==n-1||x[i+1]>0))
		l=i,r=i+1;
	now=0;
	while(l>=0||r<=n-1)
	{
		if(r==n||l>=0&&abs(x[l])<abs(x[r]))
		{

			time+=abs(x[l]-now);
			now=x[l];
			if(time>t)
				break;
			l--;
		}
		else
		{
			time+=abs(x[r]-now);
			now=x[r];
			if(time>t)
				break;
			r++;
		}

		ans++;
	}
	printf("%d\n",ans);
	return 0;
} 

