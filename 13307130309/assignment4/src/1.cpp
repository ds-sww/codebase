#include<cstdio>
#include<cstdlib>
int n,a[10001],st[10001],p;
int main()
{
	int i,j;
	scanf("%d",&n);
	while(n!=0)
	{
		scanf("%d",&a[0]);
		while(a[0]!=0)
		{
			for(i=1;i<n;i++)
				scanf("%d",&a[i]);
			for(i=0;i<n;i++)
				a[i]--;
			p=0;j=0;
			for(i=0;i<n;i++)
			{
				st[p]=i;
				p++;
				while(p>0&&j<n&&st[p-1]==a[j])
				{
					p--;
					j++;
				}
			}
			if(p==0)
				printf("Yes\n");
			else
				printf("No\n");
			scanf("%d",&a[0]);
		}
		printf("\n");
		//===========================
		scanf("%d",&n);
	}
	return 0;
}

