#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct tree
{
	int sum,s,child[100];
}f[100];
void work(int x)
{
	cout<<'('<<x;
	for (int i=f[x].s;i>0;i--)
	{
		cout<<' ';
		work(f[x].child[i]);
	}
	cout<<')';
}
int main()
{
	char str[1000];
	while(gets(str))
	{
		int n,i,j,x,a[100],t[100],temp;
		i=0;x=0;n=0;
		if (str[i]=='\0')
		{
			cout<<"(1)"<<endl;
			continue;
		}
		while (str[i]) 
		{
			if (str[i]==' ') 
			{
				a[n++]=x;
				x=0;
			}
			else x=x*10+(int)str[i]-48;
			i++;
		}
		a[n++]=x; 
		for (i=1;i<=n+1;i++)
		{
			f[i].sum=0;
			for (j=1;j<=n;j++) 
				f[i].child[j]=0;
		}
		for (i=0;i<n;i++) f[a[i]].sum++;
		for (i=1;i<=n+1;i++)
		{
			t[i]=0;f[i].s=f[i].sum;
		}
		for (i=0;i<n;i++)
			for (j=1;j<=n+1;j++)
				if ((t[j]==0)&&(f[j].sum==0))
				{
					temp=f[a[i]].sum--;
					f[a[i]].child[temp]=j;
					t[j]=1;
					break;
				}
		work(a[n-1]);	
		cout<<endl;
	}
	return 0;
}