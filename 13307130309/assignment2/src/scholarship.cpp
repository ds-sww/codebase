#include<cstdio>

int n;
int s[1000],c[1000],m[1000],e[1000],t[1000];
int main()
{
	int i,j;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&c[i],&m[i],&e[i]);
		s[i]=i;
		t[i]=c[i]+m[i]+e[i]; 
	}
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		if(t[i]<t[j]||(t[i]==t[j]&&c[i]<c[j]||t[i]==t[j]&&c[i]==c[j]&&s[i]>s[j]))
		{
			int k=s[i];
			s[i]=s[j];
			s[j]=k;
			k=t[i];
			t[i]=t[j];
			t[j]=k;
			k=c[i];
			c[i]=c[j];
			c[j]=k;
		}
	for(i=0;i<5;i++)
	{
		printf("%d %d\n",s[i]+1,t[i]);
	}
	return 0;
}
