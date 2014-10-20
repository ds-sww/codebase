#include<cstdio>
#include<cstdlib>
int s[1000003],ans,n,p;
void upplay(int i)
{
	if(i==1)
		return;
	if(s[i>>1]>s[i])
	{
		int k=s[i>>1];
		s[i>>1]=s[i];
		s[i]=k;
		upplay(i>>1);
	}
	return;
}
void downplay(int i)
{
	if(i<<1>p)
		return;
	if(i<<1+1>p&&s[i]>s[i<<1])
	{
		int k=s[i<<1];
		s[i<<1]=s[i];
		s[i]=k;
		return;
	}
	if(!(s[i]<s[i<<1]&&s[i]<s[i<<1+1]))
	{
		if(s[i<<1]<s[i<<1+1])
		{
			int k=s[i<<1];
			s[i<<1]=s[i];
			s[i]=k;
			downplay(i<<1);
		}
		else
		{
			int k=s[i<<1+1];
			s[i<<1+1]=s[i];
			s[i]=k;
			downplay(i<<1+1);
		}
	}
	
}
int main()
{
	int i,j;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&j);
		p++; 
		s[p]=j;
		upplay(p);
	}
	
	for(i=0;i<n-1;i++)
	{
		int now=s[1];
		s[1]=s[p];
		p--;
		downplay(1);
		now+=s[1];
		s[1]=s[p];
		p--;
		downplay(1);
		p++;
		s[p]=now;
		upplay(p);
		ans+=now;
	}
	printf("%d\n",ans);
	return 0;
} 
