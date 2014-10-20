#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int seq[1111111];
pii que[1111111];

int nyan(int n,int k,bool nega)
{
	int front = 0;
	int end = 0;
	for(int i = 0;i < n;i++)
	{
		while(front < end && seq[i] <= que[end-1].first) end--;
		que[end++] = pii(seq[i],i);
		while(front+1 < end && i-que[front].second >= k) front++;
		int cur = que[front].first;
		if(i >= k-1)
		{
			if(nega) cur = -cur;
			printf("%d%c",cur,i == n-1 ? '\n' : ' ');
		}
	}
	return 0;
}

int main(void)
{
	int n = 0;
	int k = 0;
	scanf("%d %d",&n,&k);
	for(int i = 0;i < n;i++) scanf("%d",&seq[i]);
	nyan(n,k,false);
	for(int i = 0;i < n;i++) seq[i] = -seq[i];
	nyan(n,k,true);
	return 0;
}
