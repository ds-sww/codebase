#include <cstdio>
#include <iostream>
using namespace std;
struct tree
{
	char name;
	int lc,rc;
};
int main()
{
	int t;
	scanf("%d\n",&t);
	while (t)
	{
		t--;
		tree a[10000];
		int i,m,n,stack[10000],queue[10000];
		char c;
		n=0;m=0;
		c=getchar();
		while (c!='\n')
		{
			a[m].name=c;
			if ((c>96)&&(c<123))
			{
				a[m].lc=-1;
				a[m].rc=-1;
			}
			else
			{
				n=n-2;
				a[m].lc=stack[n];
				a[m].rc=stack[n+1];
			}
			stack[n++]=m++;
			c=getchar();
		}
		queue[0]=m-1;n=1;
		for (i=0;i<m;i++)
		{
			if (a[queue[i]].lc!=-1) queue[n++]=a[queue[i]].lc;
			if (a[queue[i]].rc!=-1) queue[n++]=a[queue[i]].rc;
		}
		for (i=m-1;i>=0;i--) putchar(a[queue[i]].name);
		printf("\n");
	}
	return 0;
}